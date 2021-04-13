#include "../inc/Macierz2x2.hh"
#include <cmath>


Macierz2x2  Macierz2x2::operator * (const Macierz2x2 & arg2) const{
    Macierz2x2 wynik(katRad+arg2.getAngle());
    return wynik;
}

Wektor2D  Macierz2x2::operator * (const Wektor2D & wektor) const{
    Wektor2D wynik;
    wynik[0]=wektor[0]*cos(katRad)-wektor[1]*sin(katRad);
    wynik[1]=wektor[0]*sin(katRad)+wektor[1]*cos(katRad);
    return wynik;
}

std::ostream& operator << (std::ostream &Strm, const Macierz2x2 &Mac){
    Strm<<"| "<<cos(Mac.getAngle())<<'\t'<<-sin(Mac.getAngle())<<" |"<<std::endl;
    Strm<<"| "<<sin(Mac.getAngle())<<'\t'<<cos(Mac.getAngle())<<" |"<<std::endl;
    return Strm;
}