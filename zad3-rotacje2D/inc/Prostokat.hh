#ifndef PROSTOKAT_HH
#define PROSTOKAT_HH

#include <iostream>
#include <vector>
#include"../inc/Wektor2D.hh"
#include "../API2D/source/Dr2D_gnuplot_api.hh"

class Prostokat {
  private:

  int id_rysynku;
  std::vector<Wektor2D> punkty;

  public:
  void rotacja(double kat_w_deg);
  Prostokat translacja(Wektor2D wek);
  const Wektor2D & operator [] (unsigned int ind) const;
  void rysuj(drawNS::Draw2DAPI *rysownik);
  Prostokat(Wektor2D p1, Wektor2D p2, Wektor2D p3, Wektor2D p4);
  Prostokat();
};


std::ostream & operator << ( std::ostream &Strm, const Prostokat &Pr);


#endif
