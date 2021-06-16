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
    Plateau(Wektor<2> location, uint _vertNr, std::shared_ptr<drawNS::Draw3DAPI> _api, std::string _color); // vertNr = ile katow
};

#endif