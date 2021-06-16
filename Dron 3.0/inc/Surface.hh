#ifndef SURFACE_HH
#define SURFACE_HH

#include<memory>
#include"../API/source/Dr3D_gnuplot_api.hh"
#include "DrawingInterface.hh"

class Surface: public DrawingInterface {
    private:
    double height;
    public:
    Surface(double _height, std::shared_ptr<drawNS::Draw3DAPI> _api, std::string _color="black"): DrawingInterface(_api,_color), height(_height) {}
    void draw() override;
};

#endif