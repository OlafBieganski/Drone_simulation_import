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
    Hill(Wektor<2> location, uint _vertNr, std::shared_ptr<drawNS::Draw3DAPI> _api, std::string _color);
    void showVert() const {for(uint i=0;i<=vertNr;i++) std::cout<<"Wierzcholek nr "<<i<<" = "<<verticies[i]<<std::endl;}
};

#endif