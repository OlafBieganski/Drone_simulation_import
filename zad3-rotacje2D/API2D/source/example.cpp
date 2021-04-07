#include <iostream>
#include "Dr2D_gnuplot_api.hh"
#include <cmath>

using std::vector;
using drawNS::Point2D;
using drawNS::APIGnuPlot2D;
using std::cout;
using std::endl;
using std::sin;
using std::cos;

void wait4key() {
  do {
    std::cout << "\n Press a key to continue..." << std::endl;
  } while(std::cin.get() != '\n');
}

int main() {
  vector<int> ksztalty_id;
  
  std::shared_ptr<drawNS::Draw2DAPI> api(new APIGnuPlot2D(-5,5,-5,5,1000)); //włacza gnuplota, pojawia się scena [-5,5] x [-5,5] odświeżana co 1000 ms
  //drawNS::Draw3DAPI * api = new APIGnuPlot3D(-5,5,-5,5,1000); //alternatywnie zwykły wskaźnik
  api->change_ref_time_ms(0); //odświeżanie sceny zmienione na opcję "z każdym pojawieniem się lub zniknięciem kształtu"
  int a=api->draw_line(drawNS::Point2D(0,0),drawNS::Point2D(2,0)); //rysuje linię pomiędzy (0,0) a (2,0), zapamiętuje id kształtu w zmiennej a 
  int b=api->draw_line(drawNS::Point2D(0,0),drawNS::Point2D(0,5),"red"); //rysuje czerwoną linie pomiędzy (0,0,0) a (0,5)
  ksztalty_id.push_back(b);//potrzebne do usuniecia po przykladzie

  cout << endl << "Przykład A" << endl; 
  cout << endl << "pojawiły się 2 linie: czarna i czerwona" << endl;  
  wait4key();
  
  api->erase_shape(a); //usuwa kształt o id a
  cout << "czarna linia zniknęła" << endl;

  wait4key();

  b=api->draw_polygonal_chain(vector<Point2D> {drawNS::Point2D(0,0),
	drawNS::Point2D(1,4),drawNS::Point2D(4,4),
	drawNS::Point2D(4,0),drawNS::Point2D(4,0)},"purple"); //rysuje fioletową łamaną
  cout << "pojawiła się fioletowa łamana" << endl;
  
  ksztalty_id.push_back(b);//potrzebne do usuniecia po przykladzie
  
  wait4key();
  api->change_ref_time_ms(1000);
  b=api->draw_polygonal_chain(vector<Point2D> {drawNS::Point2D(0,0),
	drawNS::Point2D(0,-4),drawNS::Point2D(-2,-4),
	drawNS::Point2D(-4,0),drawNS::Point2D(-4,0)},"green");
  cout << "pojawiła się zielona łamana" << endl;
  
  wait4key();
  api->change_shape_color(b,"yellow");//zmienia kolor
  cout << "zmiana koloru z zielonej na żółtą" << endl;

  ksztalty_id.push_back(b);//potrzebne do usuniecia po przykladzie
    
  wait4key();
  
  api->change_ref_time_ms(-1);//odświerzanie sceny zmienione na opcję "tylko za pomocą metody redraw()"
    
  b=api->draw_polygonal_chain(vector<Point2D> {drawNS::Point2D(0,0),
	drawNS::Point2D(0.5,2),drawNS::Point2D(2,2),
	drawNS::Point2D(2,0),drawNS::Point2D(2,0)},"blue"); //dodaje do rysowania niebieska łamaną
  cout << "dodano niebieską łamaną" << endl;

  ksztalty_id.push_back(b);//potrzebne do usuniecia po przykladzie
  
  wait4key();

  api->redraw();//odświerzenie sceny
  cout << "dopiero teraz pojawiła się niebieska łamana" << endl;

  wait4key();

  for (int & x : ksztalty_id) {
    api->erase_shape(x);
  } //wyczyszczono
  
  b=api->draw_polygonal_chain(vector<Point2D> {
      drawNS::Point2D(1,1),
	drawNS::Point2D(1,3),
	drawNS::Point2D(4,3),
	drawNS::Point2D(4,1),
	drawNS::Point2D(1,1)},
    "blue");

  cout << endl << "Przykład B" << endl;
  cout << "Prostokąt (1,1) -- (4,3)" << endl;

  api->redraw();
  
  wait4key();

  double katrad=3.14*45/180.0;
  
  api->draw_polygonal_chain(vector<Point2D> {
      drawNS::Point2D(cos(katrad)*1-sin(katrad)*1,sin(katrad)*1+cos(katrad)*1),
      drawNS::Point2D(cos(katrad)*1-sin(katrad)*3,sin(katrad)*1+cos(katrad)*3),
      drawNS::Point2D(cos(katrad)*4-sin(katrad)*3,sin(katrad)*4+cos(katrad)*3),
      drawNS::Point2D(cos(katrad)*4-sin(katrad)*1,sin(katrad)*4+cos(katrad)*1),
      drawNS::Point2D(cos(katrad)*1-sin(katrad)*1,sin(katrad)*1+cos(katrad)*1)},
      "red");

  api->redraw();
  
  cout << "Obrócony wokół (0,0) o 45 stopni" << endl;
  
  wait4key();

  katrad=3.14*60/180.0;
  
  api->draw_polygonal_chain(vector<Point2D> {
      drawNS::Point2D(cos(katrad)*1-sin(katrad)*1,sin(katrad)*1+cos(katrad)*1),
      drawNS::Point2D(cos(katrad)*1-sin(katrad)*3,sin(katrad)*1+cos(katrad)*3),
      drawNS::Point2D(cos(katrad)*4-sin(katrad)*3,sin(katrad)*4+cos(katrad)*3),
      drawNS::Point2D(cos(katrad)*4-sin(katrad)*1,sin(katrad)*4+cos(katrad)*1),
      drawNS::Point2D(cos(katrad)*1-sin(katrad)*1,sin(katrad)*1+cos(katrad)*1)},
      "green");

  api->redraw();
  
  cout << "Obrócony wokół (0,0) o 60 stopni" << endl;
  
  wait4key();

    katrad=3.14*180/180.0;
  
  api->draw_polygonal_chain(vector<Point2D> {
      drawNS::Point2D(cos(katrad)*1-sin(katrad)*1,sin(katrad)*1+cos(katrad)*1),
      drawNS::Point2D(cos(katrad)*1-sin(katrad)*3,sin(katrad)*1+cos(katrad)*3),
      drawNS::Point2D(cos(katrad)*4-sin(katrad)*3,sin(katrad)*4+cos(katrad)*3),
      drawNS::Point2D(cos(katrad)*4-sin(katrad)*1,sin(katrad)*4+cos(katrad)*1),
      drawNS::Point2D(cos(katrad)*1-sin(katrad)*1,sin(katrad)*1+cos(katrad)*1)},
      "yellow");

  api->redraw();
  
  cout << "Obrócony wokół (0,0) o 180 stopni" << endl;
  
  wait4key();
  
  //delete api;//dla zwykłych wskaźników musimy posprzątać
}
