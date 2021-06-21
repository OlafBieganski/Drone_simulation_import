#ifndef DRAWINGINTERFACE
#define DRAWINGINTERFACE

#include "../API/source/Dr3D_gnuplot_api.hh"

class DrawingInterface{
    protected:
    uint shapeID=1000; // patrz NOTDRAWN w Scene.cpp
    std::shared_ptr<drawNS::Draw3DAPI> api;
    std::string color="black";
    public:
    DrawingInterface(std::shared_ptr<drawNS::Draw3DAPI> _api, std::string _color="black") {api=_api;color=_color;}
    DrawingInterface() = default;
    virtual void draw() = 0;
    uint getID() {return shapeID;}
    void setID(uint id) {shapeID=id;}
};

#endif