/*
Copyright 2021 Arkadiusz Mielczarek

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
*/

#include "Dr2D_gnuplot_api.hh"
#include <iostream>
#include <sstream>
#include <unistd.h>

using drawNS::Point2D;
using drawNS::APIGnuPlot2D;
using std::string;
using std::stringstream;
using std::endl;
using std::vector;
using std::list;
using std::map;
using std::pair;
using std::thread;
using std::unique_ptr;
using std::mutex;

std::ostream & operator<<(std::ostream & strm, const Point2D & point) {
  strm << point[0] << " " << point[1] << std::endl;
  return strm;
}

APIGnuPlot2D::APIGnuPlot2D(double minX, double maxX, double minY, double maxY, int ref_time_ms): Draw2DAPI(ref_time_ms), refresh_thread_ptr(nullptr), last_shape(0) {
  pipe(pipe_fd);
  int local_pid=fork();
  if(local_pid != 0) {
    gnuplot_pid=local_pid;
    stringstream ss_tmp;

    ss_tmp << " set terminal qt" << endl
           << "set xrange [" << minX << ":" << maxX << "]" << endl
           << "set yrange [" << minY << ":" << maxY << "]" << endl
           << "set xlabel \"X\"" << endl
           << "set ylabel \"Y\"" << endl
           << "set size ratio -1" << endl
           << "unset key" << endl;

    intro = ss_tmp.str();
    send2gnuplot(intro);
    if (ref_time_ms > 0) {
      refresh_thread_ptr.reset(new thread(&APIGnuPlot2D::replot_loop,this));
      refresh_thread_ptr->detach();
    }
  }
  else {
    dup2(pipe_fd[0],0);
    std::cerr << "gnuplot is running" << endl;
    execlp("gnuplot","gnuplot",NULL);
  }
}

void APIGnuPlot2D::send2gnuplot(const string & command_arg){
  gnuplot_pipe_mutex.lock();
  write(pipe_fd[1],command_arg.c_str(),command_arg.length());
  gnuplot_pipe_mutex.unlock();
}

void APIGnuPlot2D::replot_loop(){
  while(refresh_rate_ms > 0) {
    draw_all_shapes();
    std::this_thread::sleep_for(std::chrono::milliseconds(refresh_rate_ms));
  }
}

uint APIGnuPlot2D::add2shape_list(const list<list<Point2D> > & _list, const string & color) {
  shapes.insert(std::pair<uint,shape_and_color>(last_shape,std::make_pair(_list,color)));
  return last_shape++;
}

void APIGnuPlot2D::draw_all_shapes() {

  stringstream ss;
  string color;
  ss << intro << "plot ";
  for (auto itel = shapes.begin();itel!=shapes.end();) {
    color = translate_color(itel->second.second);
    if (!color.compare("error")) {
      color = translate_color("black");
      std::cerr << "Shape nr " << itel->first << " has invalid color.\nUsing black color to draw it." << endl;
    } 
    ss << "\'-\' using 1:2 with lines lt 1 lw 3 " << color;
    if (++itel != shapes.end())
      ss << ",";
  }
  ss << endl;
  for (auto & el : shapes) {
    for (auto & inel : el.second.first) {
      for (auto & in2el : inel) {
	ss << in2el;
      }
      ss << endl;
    }
    ss<< "e" << endl;	
  }
  ss << "pause -1" << endl;
  command = ss.str();
  send2gnuplot(command);
}

string APIGnuPlot2D::translate_color(const string & color) const {
  string out = "lc rgb \'#";
  if (!color.compare("black"))
    return out+"000000\'";
  if (!color.compare("white"))
    return out+"ffffff\'";
  if (!color.compare("grey"))
    return out+"808080\'";
  if (!color.compare("blue"))
    return out+"0072bd\'";
  if (!color.compare("orange"))
    return out+"d95319\'";
  if (!color.compare("yellow"))
    return out+"edb120\'";
  if (!color.compare("purple"))
    return out+"7e2f8e\'";
  if (!color.compare("green"))
    return out+"77ac30\'";
  if (!color.compare("light-blue"))
    return out+"4dbeee\'";
  if (!color.compare("red"))
    return out+"a2142f\'";
  if (!color.compare(0,5,"rgb:#"))
    return out+color.substr(5);
  return "error";
}

uint APIGnuPlot2D::draw_line(const Point2D & point1, const Point2D & point2, const string & color ) {
  uint tmp = add2shape_list(list<list<Point2D> > {{point1,point2}},color);
  if (refresh_rate_ms == 0) {
    draw_all_shapes();
  }
  return tmp;
}

uint APIGnuPlot2D::draw_polygonal_chain(const vector<Point2D> & points, const string & color ) {
  uint tmp = add2shape_list(list<list<Point2D> > {list<Point2D>(begin(points),end(points))},color);
  if (refresh_rate_ms == 0) {
    draw_all_shapes();
  }
  return tmp;
}

void APIGnuPlot2D::erase_shape(uint id) {
  shapes.erase(id);
  if (refresh_rate_ms == 0) {
    draw_all_shapes();
  }
}

void APIGnuPlot2D::change_shape_color(uint id, const string & color) {
  if (shapes.count(id)) {
    shapes[id].second=color;
  }
  if (refresh_rate_ms == 0) {
    draw_all_shapes();
  }  
}

void APIGnuPlot2D::stop_drawing_proces() {
  stringstream killstream;
  std::cerr << "gnuplot stops running" << std::endl;
  killstream << "kill " << gnuplot_pid;
  system(killstream.str().c_str());
}

void APIGnuPlot2D::change_ref_time_ms(int ref_time_ms) {
  if (ref_time_ms <= 0) {
    refresh_thread_ptr.reset();
  } else {
    refresh_thread_ptr.reset(new thread(&APIGnuPlot2D::replot_loop,this));
    refresh_thread_ptr->detach();
  }
  refresh_rate_ms = ref_time_ms;
}

void APIGnuPlot2D::redraw() {
    if (refresh_rate_ms < 0)
     draw_all_shapes();
}
