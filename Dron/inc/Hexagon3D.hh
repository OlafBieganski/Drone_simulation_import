#ifndef HEXAGON3D
#define HEXAGON3D

#include "DrawingInterface.hh"

class Hexagon3D:public DrawingInterface, public CoordinateSys{
    void draw() const;
};

#endif