#ifndef PROSTOPADLOSCIAN_HH
#define PROSTOPADLOSCIAN_HH

#include "../API/source/Dr3D_gnuplot_api.hh"
#include "Wektor.hh"
#include "MacierzObr.hh"
#include <array>


class Prostopadloscian{
    private:
    std::array<Wektor<3>, 8> punkty;
    public:
    Prostopadloscian(std::array<Wektor<3>, 4> podstawa, double wysokosc);
    void translacja(Wektor<3> przesuniecie);
    void rotacja(MacierzObr<3> obrot);
    const Wektor<3> operator [] (unsigned int ind) const;
    void rysuj(std::shared_ptr<drawNS::Draw3DAPI> rysownik) const;
    std::array<std::array<double,4>,3> dlugoscKrawedzi() const;
};


#endif