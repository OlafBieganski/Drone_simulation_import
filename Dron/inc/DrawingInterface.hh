#ifndef DRAWINGINTERFACE
#define DRAWINGINTERFACE

#include "../API/source/Dr3D_gnuplot_api.hh"

class DrawingInterface{
    public:
    virtual void draw(std::shared_ptr<drawNS::Draw3DAPI> api) const = 0;
};

#endif