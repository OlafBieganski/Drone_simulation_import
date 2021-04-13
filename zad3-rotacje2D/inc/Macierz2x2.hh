#ifndef MACIERZ2X2_HH
#define MACIERZ2X2_HH

#include <iostream>
#include "../inc/Wektor2D.hh"


class Macierz2x2 {
  private:
  double katRad; // w radianach 
  public:
  Macierz2x2() {katRad=0.0;};
  Macierz2x2(double _katRad) {katRad=_katRad;}
  void setAngle(double _katRad) {katRad=_katRad;};
  const double & getAngle() const {return katRad;};
  Macierz2x2  operator * (const Macierz2x2 & arg2) const;
  Wektor2D  operator * (const Wektor2D & wektor) const;
};


std::ostream& operator << (std::ostream &Strm, const Macierz2x2 &Mac);

#endif
