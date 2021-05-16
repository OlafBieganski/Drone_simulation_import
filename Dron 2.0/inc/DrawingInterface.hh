#ifndef DRAWINGINTERFACE
#define DRAWINGINTERFACE

#include "../API/source/Dr3D_gnuplot_api.hh"

class DrawingInterface{
    protected:
    std::vector<int> shapeID;
    std::shared_ptr<drawNS::Draw3DAPI> api;
    std::string color="black";
    public:
    DrawingInterface(std::shared_ptr<drawNS::Draw3DAPI> _api, std::string _color="black") {api=_api;color=_color;}
    DrawingInterface() = default;
    virtual void draw() = 0;
    int getID(uint index) {return shapeID[index];}
    bool emptyID() {if(shapeID.empty()) return true;return false;}
    void popBackID() {shapeID.pop_back();}
    void pushBackID(int id) {shapeID.push_back(id);}
};

#endif