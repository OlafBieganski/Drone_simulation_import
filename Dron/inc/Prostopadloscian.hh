#ifndef PROSTOPADLOSCIAN_HH
#define PROSTOPADLOSCIAN_HH

#include "../API/source/Dr3D_gnuplot_api.hh"
#include "Wektor.hh"
#include "MacierzObr.hh"
#include "DrawingInterface.hh"
#include "CoordinateSys.hh"
#include <array>


class Prostopadloscian: public CoordinateSys, public DrawingInterface {
    private:
    std::array<Wektor<3>, 8> punkty;
    public:
    Prostopadloscian(Wektor<3> baseMid, MacierzObr<3> baseOrient, std::array<Wektor<3>, 4> podstawa, double wysokosc);
    void translacja(Wektor<3> przesuniecie);
    void rotacja(MacierzObr<3> obrot);
    const Wektor<3> operator [] (unsigned int ind) const;
    void draw(std::shared_ptr<drawNS::Draw3DAPI> api) const;
    std::array<std::array<double,4>,3> dlugoscKrawedzi() const;
};


#endif