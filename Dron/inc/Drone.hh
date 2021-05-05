#ifndef DRONE
#define DRONE

#include "Prostopadloscian.hh"
#include "Hexagon3D.hh"
#include <iostream>

using std::array;

class Drone{
    private:
    Prostopadloscian frame;
    array<Hexagon3D,4> rotors;
    public:
    void draw() const;
    void fly(double angleOZ, double height, double distance);
    Drone(Wektor<3> middlePosition);
};


#endif