#ifndef HILL_HH
#define HILL_HH

#include "DrawingInterface.hh"
#include "CoordinateSys.hh"

class Hill: public DrawingInterface, public CoordinateSys {
    private:
    std::vector<Wektor<3>> verticies;
    uint vertNr; // ilosc wiercholkow podstawy
    public:
    void draw() override;
    Hill(Wektor<2> location, uint _vertNr);
};

#endif