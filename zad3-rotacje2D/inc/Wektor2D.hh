#ifndef WEKTOR2D_HH
#define WEKTOR2D_HH

#include <iostream>
#include <vector>
#include "../API2D/source/Dr2D_gnuplot_api.hh"
#include <cmath>


class Wektor2D {
  private:
  std::vector<double> xy;
  public:
  Wektor2D() {xy.push_back(0.0); xy.push_back(0.0);};
  Wektor2D(double _x, double _y) {xy.push_back(_x); xy.push_back(_y);};
  Wektor2D operator + (const Wektor2D & arg2) const;
  Wektor2D operator - (const Wektor2D & arg2) const;
  double operator * (const Wektor2D & arg2) const;
  const double & operator [] (int ind) const;
  double & operator [] (int ind);
  bool operator == (const Wektor2D & arg2) const;
  double modul() const {return sqrt(pow(xy[0], 2)+pow(xy[1], 2));}
};

drawNS::Point2D konwertuj(Wektor2D arg);


std::istream& operator >> (std::istream &Strm, Wektor2D &Wek);


std::ostream& operator << (std::ostream &Strm, const Wektor2D &Wek);

#endif
