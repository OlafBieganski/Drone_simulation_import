#ifndef DRONE
#define DRONE

#include "Prostopadloscian.hh"
#include "Hexagon3D.hh"
#include "CoordinateSys.hh"
#include <iostream>
#include "../API/source/Dr3D_gnuplot_api.hh"

using std::array;

class Drone: public CoordinateSys {
    private:
    Prostopadloscian frame;
    array<Hexagon3D,4> rotors;
    public:
    void draw(std::shared_ptr<drawNS::Draw3DAPI> api) const;
    void flyUp(double height);
    void flyVert(double distance);
    void turn(double angle_deg);
    Drone(Wektor<3> droneMiddle);
};


#endif