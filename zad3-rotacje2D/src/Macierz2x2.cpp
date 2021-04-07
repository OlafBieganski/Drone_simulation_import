#include "../inc/Macierz2x2.hh"
#include <cmath>


const Macierz2x2  Macierz2x2::operator * (const Macierz2x2 & arg2) const{
    Macierz2x2 wynik(kat+arg2.getAngle());
    return wynik;
}

const Wektor2D  Macierz2x2::operator * (const Wektor2D & wektor) const{
    Wektor2D wynik;
    wynik[0]=wektor[0]*cos(kat)-wektor[1]*sin(kat);
    wynik[1]=wektor[0]*sin(kat)+wektor[1]*cos(kat);
    return wynik;
}

std::ostream& operator << (std::ostream &Strm, const Macierz2x2 &Mac){
    Strm<<Mac.getAngle();
    return Strm;
}