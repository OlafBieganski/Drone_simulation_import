#ifndef MACIERZ_HH
#define MACIERZ_HH

#include <iostream>
#include "../inc/Wektor.hh"
#include <cmath>

template<unsigned int R>
class Macierz {
  private:
  std::vector<Wektor<R>> wiersze;
  public:
  Macierz();
  Macierz(double _katRad, std::string axis = "OZ");
  Macierz  operator * (const Macierz & arg2) const;
  Wektor  operator * (const Wektor & wektor) const;
  const Wektor<R> & operator [] (unsigned int id) const;
};

/*
std::ostream& operator << (std::ostream &Strm, const Macierz &Mac);



Macierz  Macierz::operator * (const Macierz & arg2) const{
    Macierz wynik(katRad+arg2.getAngle());
    return wynik;
}

Wektor  Macierz::operator * (const Wektor & wektor) const{
    Wektor wynik;
    wynik[0]=wektor[0]*cos(katRad)-wektor[1]*sin(katRad);
    wynik[1]=wektor[0]*sin(katRad)+wektor[1]*cos(katRad);
    return wynik;
}

std::ostream& operator << (std::ostream &Strm, const Macierz &Mac){
    Strm<<"| "<<cos(Mac.getAngle())<<'\t'<<-sin(Mac.getAngle())<<" |"<<std::endl;
    Strm<<"| "<<sin(Mac.getAngle())<<'\t'<<cos(Mac.getAngle())<<" |"<<std::endl;
    return Strm;
}
*/
#endif
