#ifndef PROSTOPADLOSCIAN_HH
#define PROSTOPADLOSCIAN_HH

#include "DrawingInterface.hh"
#include "../API/source/Dr3D_gnuplot_api.hh"
#include "Wektor.hh"
#include "MacierzObr.hh"
#include "CoordinateSys.hh"
#include <array>


class Prostopadloscian: public DrawingInterface, public CoordinateSys {
    protected:
    std::array<Wektor<3>, 8> punkty;
    public:
    Prostopadloscian(std::array<Wektor<3>, 4> podstawa, double wysokosc, std::shared_ptr<drawNS::Draw3DAPI> _api, std::string _color, Wektor<3> baseMid=Wektor<3>(),
     MacierzObr<3> baseOrient=MacierzObr<3>(), CoordinateSys *ptr_to_parent=nullptr);
    void translacja(Wektor<3> przesuniecie);
    void rotacja(MacierzObr<3> obrot);
    const Wektor<3> operator [] (unsigned int ind) const;
    void draw() override;
    std::array<std::array<double,4>,3> dlugoscKrawedzi() const;
    Prostopadloscian(): CoordinateSys() {punkty.fill(Wektor<3>());}; // konstruktor potrzebny w klasie dron
    void setCoord(Wektor<3> baseMid, MacierzObr<3> baseOrient, CoordinateSys *ptr_to_parent)
    {parent=ptr_to_parent;middle=baseMid;orientation=baseOrient;}
    Prostopadloscian convert_to_parent() const;
};


#endif