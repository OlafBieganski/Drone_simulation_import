#ifndef DRONE
#define DRONE

#include "Prostopadloscian.hh"
#include "Hexagon3D.hh"
#include "CoordinateSys.hh"
#include <iostream>

using std::array;

class Drone: public CoordinateSys {
    private:
    Prostopadloscian frame;
    array<Hexagon3D,4> rotors;
    public:
    void draw() const;
    void fly(double angleOZ, double height, double distance);
    Drone(Wektor<3> middlePosition);
};


#endif