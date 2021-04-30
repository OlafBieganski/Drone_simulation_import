#ifndef MACIERZOBR_HH
#define MACIERZOBR_HH

#include <iostream>
#include "Wektor.hh"
#include <cmath>

using std::cout;
using std::endl;

template<unsigned int R>
class MacierzObr {
  private:
  std::vector<Wektor<R>> wiersze;
  Wektor<R> & operator [] (unsigned int id);
  public:
  MacierzObr();
  MacierzObr(double _katRad, std::string axis="OZ");
  MacierzObr<R>  operator * (const MacierzObr<R> & arg2) const;
  Wektor<R>  operator * (const Wektor<R> & wektor) const;
  const Wektor<R> & operator [] (unsigned int id) const;
};

template <unsigned int R>
std::ostream& operator << (std::ostream &Strm, const MacierzObr<R> &Mac);

#endif
