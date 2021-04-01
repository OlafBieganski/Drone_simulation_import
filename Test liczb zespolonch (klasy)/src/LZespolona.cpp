#include "../inc/LZespolona.hh"
#define EPSILON 0.000001

LZespolona::LZespolona(double _re, double _im): re(_re), im(_im) {}

LZespolona::LZespolona(double _re): re(_re), im(0.0) {}

LZespolona::LZespolona(): re(0.0), im(0.0) {}

/*!
 * Realizuje dodanie dwoch liczb zespolonych.
 * Argumenty:
 *    Skl1 - pierwszy skladnik dodawania,
 *    Skl2 - drugi skladnik dodawania.
 * Zwraca:
 *    Sume dwoch skladnikow przekazanych jako parametry.
 */
LZespolona LZespolona::operator + (const LZespolona &  Skl2) const
{
  LZespolona  Wynik;

  Wynik.re = re + Skl2.re;
  Wynik.im = im + Skl2.im;
  return Wynik;
}

LZespolona LZespolona::operator - (const LZespolona &  Skl2) const{
  LZespolona Wynik;
  Wynik.re = re - Skl2.re;
  Wynik.im = im - Skl2.im;
  return Wynik;
}

std::ostream & operator << (std::ostream & strm, const LZespolona & L){
  strm << "(" << L.get_re() << std::showpos << L.get_im() << std::noshowpos << "i)";
  return strm;
}

std::istream & operator >>(std::istream & strm, LZespolona & L){
  char tmp;
  double _re, _im;
  strm>>tmp;
  if(tmp!='('){
    strm.setstate(std::ios::failbit);
    return strm;
  }
  strm>>_re;
  L.set_re(_re);
  strm>>_im;
  L.set_im(_im);
  strm>>tmp;
  if(tmp!='i'){
    strm.setstate(std::ios::failbit);
    return strm;
  }
  strm>>tmp;
  if(tmp!=')'){
    strm.setstate(std::ios::failbit);
  }

  return strm;
}

LZespolona LZespolona::operator * (const LZespolona &  Skl2) const{
  LZespolona Wynik;
  Wynik.re = (re*Skl2.re) - (im*Skl2.im);
  Wynik.im = (im*Skl2.re) + (re*Skl2.im);
  return Wynik;
}

LZespolona LZespolona::sprzezenie() const{
  LZespolona wynik=*this;
  wynik.set_im(-this->get_im());
  return wynik;
}

double  LZespolona::modulKwadrat() const{
  return (re*re)+(im*im);
}

LZespolona  LZespolona::operator / (const double & Skl2) const{
  LZespolona Wynik;
  Wynik.re = re / Skl2;
  Wynik.im = im / Skl2;
  return Wynik;
}

LZespolona LZespolona::operator / (const LZespolona &  Skl2) const{
  LZespolona wynik;
  double modul2=Skl2.modulKwadrat();

  wynik=(*this*Skl2.sprzezenie())/modul2;

  return wynik;
}

bool  LZespolona::operator == (const LZespolona &  Skl2) const{
  return ((abs(re-Skl2.re)<EPSILON) && (abs(im-Skl2.im)<EPSILON));
}

bool  LZespolona::operator != (const LZespolona &  Skl2) const{
  return !(*this==Skl2);
}

