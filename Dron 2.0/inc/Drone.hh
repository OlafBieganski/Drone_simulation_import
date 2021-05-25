#ifndef DRONE
#define DRONE

#include "Prostopadloscian.hh"
#include "DrawingInterface.hh"
#include "Hexagon3D.hh"
#include "CoordinateSys.hh"
#include <iostream>
#include "../API/source/Dr3D_gnuplot_api.hh"

using std::array;

class Drone: public CoordinateSys, public DrawingInterface {
    private:
    Prostopadloscian frame;
    array<Hexagon3D,4> rotors;
    void moveRotors();
    public:
    void draw() override;
    void flyHoriz(double height);
    void flyVert(double distance);
    void turn(double angle_deg);
    void land();
    Drone(Wektor<3> droneMiddle, std::shared_ptr<drawNS::Draw3DAPI> api, std::string color="black");
    void eraseDrone();
    void animatedFly(double angle_deg, double height, double distance);
    Wektor<2> getCoord() const;
};


#endif