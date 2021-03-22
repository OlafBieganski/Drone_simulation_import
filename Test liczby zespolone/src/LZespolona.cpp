#include "../inc/LZespolona.hh"
#define EPSILON 0.000001

LZespolona inicjuj(double re, double im){
  LZespolona L1;
  L1.re = re;
  L1.im = im;
  return L1;
}

/*!
 * Realizuje dodanie dwoch liczb zespolonych.
 * Argumenty:
 *    Skl1 - pierwszy skladnik dodawania,
 *    Skl2 - drugi skladnik dodawania.
 * Zwraca:
 *    Sume dwoch skladnikow przekazanych jako parametry.
 */
LZespolona  operator + (LZespolona  Skl1,  LZespolona  Skl2)
{
  LZespolona  Wynik;

  Wynik.re = Skl1.re + Skl2.re;
  Wynik.im = Skl1.im + Skl2.im;
  return Wynik;
}

LZespolona  operator - (LZespolona  Skl1,  LZespolona  Skl2){
  LZespolona Wynik;
  Wynik.re = Skl1.re - Skl2.re;
  Wynik.im = Skl1.im - Skl2.im;
  return Wynik;
}

std::ostream & operator << (std::ostream & strm, const LZespolona & L){
  strm << "(" << L.re << std::showpos << L.im << std::noshowpos << "i)";
  return strm;
}

std::istream & operator >>(std::istream & strm, LZespolona & L){
  char tmp;
  strm>>tmp;
  if(tmp!='('){
    strm.setstate(std::ios::failbit);
    return strm;
  }
  strm>>L.re;
  strm>>L.im;
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

LZespolona  operator * (LZespolona  Skl1,  LZespolona  Skl2){
  LZespolona Wynik;
  Wynik.re = (Skl1.re*Skl2.re) - (Skl1.im*Skl2.im);
  Wynik.im = (Skl1.im*Skl2.re) + (Skl1.re*Skl2.im);
  return Wynik;
}

LZespolona sprzezenie(LZespolona Skl){
  Skl.im*=-1;
  return Skl;
}

double  modulKwadrat(LZespolona skl){
  return (skl.re*skl.re)+(skl.im*skl.im);
}

LZespolona  operator / (LZespolona  Skl1,  double Skl2){
  LZespolona Wynik;
  Wynik.re = Skl1.re / Skl2;
  Wynik.im = Skl1.im / Skl2;
  return Wynik;
}

LZespolona  operator / (LZespolona  Skl1,  LZespolona  Skl2){
  LZespolona wynik;
  double modul2=modulKwadrat(Skl2);

  wynik=(Skl1*sprzezenie(Skl2))/modul2;

  return wynik;
}

bool  operator == (LZespolona  Skl1,  LZespolona  Skl2){
  return ((abs(Skl1.re-Skl2.re)<EPSILON) && (abs(Skl1.im-Skl2.im)<EPSILON));
}

bool  operator != (LZespolona  Skl1,  LZespolona  Skl2){
  return !(Skl1==Skl2);
}

