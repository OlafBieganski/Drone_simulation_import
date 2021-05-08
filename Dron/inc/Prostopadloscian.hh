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
    Prostopadloscian(std::array<Wektor<3>, 4> podstawa, double wysokosc, Wektor<3> baseMid=Wektor<3>(),
     MacierzObr<3> baseOrient=MacierzObr<3>(), CoordinateSys *ptr_to_parent=nullptr);
    void translacja(Wektor<3> przesuniecie);
    void rotacja(MacierzObr<3> obrot);
    const Wektor<3> operator [] (unsigned int ind) const;
    void draw(std::shared_ptr<drawNS::Draw3DAPI> api) const;
    std::array<std::array<double,4>,3> dlugoscKrawedzi() const;
    Prostopadloscian(): CoordinateSys() {punkty.fill(Wektor<3>());}; // konstruktor potrzebny w klasie dron
};


#endif