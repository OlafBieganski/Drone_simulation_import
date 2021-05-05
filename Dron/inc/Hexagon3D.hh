#ifndef HEXAGON3D
#define HEXAGON3D

#include "DrawingInterface.hh"
#include <array>

class Hexagon3D:public DrawingInterface, public CoordinateSys{
    private:
    std::array<Wektor<3>,12> verticies;
    public:
    void draw() const;
    void translation(Wektor<3> shift);
    void rotation(MacierzObr<3> rotationMatrix);
    const Wektor<3> operator [] (unsigned int ind) const;
    void draw(std::shared_ptr<drawNS::Draw3DAPI> api) const;
};

#endif