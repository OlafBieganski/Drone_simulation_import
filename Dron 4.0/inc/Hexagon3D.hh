#ifndef HEXAGON3D
#define HEXAGON3D

#include "DrawingInterface.hh"
#include "CoordinateSys.hh"
#include <array>
#include "../API/source/Dr3D_gnuplot_api.hh"

class Hexagon3D:public DrawingInterface, public CoordinateSys {
    private:
    std::array<Wektor<3>,12> verticies;
    public:
    void translation(Wektor<3> shift);
    void rotation(MacierzObr<3> rotationMatrix);
    const Wektor<3> operator [] (unsigned int ind) const;
    void draw() override;
    Hexagon3D(std::array<Wektor<3>,6> base, double height, std::shared_ptr<drawNS::Draw3DAPI> _api, std::string _color, Wektor<3> baseMid=Wektor<3>(),
     MacierzObr<3> baseOrient=MacierzObr<3>(), CoordinateSys *ptr_to_parent=nullptr);
    Hexagon3D(Wektor<3> middle, double diagonal, double height, std::shared_ptr<drawNS::Draw3DAPI> _api, std::string _color);
    Hexagon3D();
    void setCoord(Wektor<3> baseMid, MacierzObr<3> baseOrient, CoordinateSys *ptr_to_parent)
    {parent=ptr_to_parent;middle=baseMid;orientation=baseOrient;}
    Hexagon3D convert_to_parent() const;
    Hexagon3D convert_to_granpa() const;
};

#endif