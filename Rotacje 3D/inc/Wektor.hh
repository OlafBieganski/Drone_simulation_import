#ifndef WEKTOR_HH
#define WEKTOR_HH

#include <iostream>
#include <vector>
#include <cmath>
#include <initializer_list>
#include <iomanip>


template<unsigned int R>
class Wektor {
  private:
  std::vector<double> tab;
  public:
  Wektor(){for(unsigned int i=0;i<R;++i) tab.push_back(0.0);};
  Wektor(std::initializer_list<double> l): tab(l) {}
  Wektor<R> operator + (const Wektor<R> & arg2) const;
  Wektor<R> operator - (const Wektor<R> & arg2) const;
  double operator * (const Wektor<R> & arg2) const;
  Wektor<R> operator * (const double & arg2) const;
  const double & operator [] (unsigned int ind) const;
  double & operator [] (unsigned int ind);
  bool operator == (const Wektor<R> & arg2) const;
  bool operator != (const Wektor<R> & arg2) const;
  double modul() const;
};

template<unsigned int R>
std::istream& operator >> (std::istream &Strm, Wektor<R> &Wek);

template<unsigned int R>
std::ostream& operator << (std::ostream &Strm, const Wektor<R> &Wek);

#endif
