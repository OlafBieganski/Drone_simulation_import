#ifndef PROSTOPADLOSCIAN_HH
#define PROSTOPADLOSCIAN_HH

#include "Wektor.hh"
#include "MacierzObr.hh"
#include <array>

class Prostopadloscian{
    private:
    std::array<Wektor<3>, 8> punkty;
    public:
    Prostopadloscian(std::array<Wektor<3>, 4> podstawa, double wysokosc);
    void translacja(Wektor<3> przesuniecie);
    void rotacja(double katwRad, std::string axis);
    const Wektor<3> operator [] (unsigned int ind) const;
};


#endif