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
    std::vector<int> shapeID;
    void moveRotors();
    public:
    void draw(std::shared_ptr<drawNS::Draw3DAPI> api);
    void flyHoriz(double height);
    void flyVert(double distance);
    void turn(double angle_deg);
    void land();
    Drone(Wektor<3> droneMiddle);
    bool eraseDrone(std::shared_ptr<drawNS::Draw3DAPI> api);
    void animatedFly(double angle_deg, double height, double distance, std::shared_ptr<drawNS::Draw3DAPI> api);
};


#endif