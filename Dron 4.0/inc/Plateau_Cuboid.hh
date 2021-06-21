#ifndef PLATEAUCUBOID_HH
#define PLATEAUCUBOID_HH

#include "Prostopadloscian.hh"

class Plateau_Cuboid: public Prostopadloscian {
    public:
    Plateau_Cuboid(Wektor<2> location, double heightZ, double widthX, double lenghtY, std::shared_ptr<drawNS::Draw3DAPI> _api, std::string _color);
};

#endif