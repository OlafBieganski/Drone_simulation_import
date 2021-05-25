#ifndef PLATEAU_HH
#define PLATEAU_HH

#include "DrawingInterface.hh"
#include "CoordinateSys.hh"

class Plateau: public DrawingInterface, public CoordinateSys {
    private:
    std::vector<Wektor<3>> verticies;
    uint vertNr; // ilosc wiercholkow podstawy
    public:
    void draw() override;
    Plateau(Wektor<2> location, uint _vertNr); // vertNr = ile katow
};

#endif