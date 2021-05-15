#ifndef SURFACE_HH
#define SURFACE_HH

#include<memory>
#include"../API/source/Dr3D_gnuplot_api.hh"

class Surface{
    private:
    double height;
    public:
    Surface(): height(0.0) {}
    Surface(double _height): height(_height) {}
    void draw(std::shared_ptr<drawNS::Draw3DAPI> api, std::string color) const;
};

#endif