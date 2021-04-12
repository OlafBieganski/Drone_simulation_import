#ifndef MACIERZ2X2_HH
#define MACIERZ2X2_HH

#include <iostream>
#include "../inc/Wektor2D.hh"


class Macierz2x2 {
  private:
  double kat;
  public:
  Macierz2x2() {kat=0.0;};
  Macierz2x2(double _kat) {kat=_kat;}
  void setAngle(double _kat) {kat=_kat;};
  const double & getAngle() const {return kat;};
  Macierz2x2  operator * (const Macierz2x2 & arg2) const;
  Wektor2D  operator * (const Wektor2D & wektor) const;
};


/*
 * To przeciazenie trzeba opisac. Co ono robi. Jaki format
 * danych akceptuje. Jakie jest znaczenie parametrow itd.
 * Szczegoly dotyczace zalecen realizacji opisow mozna
 * znalezc w pliku:
 *    ~bk/edu/kpo/zalecenia.txt 
 *
 * Przeciążenie to może być użyteczne w trakcie debugowania programu.
 */
std::ostream& operator << (std::ostream &Strm, const Macierz2x2 &Mac);

#endif
