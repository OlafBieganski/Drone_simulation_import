#include "Drone.hh"
#include "LandscapeInterface.hh"

using std::vector;

class Scene{
    private:
    vector<DrawingInterface*> toDraw;
    vector<LandscapeInterface*> landscapeItem;
    public:
    void drawAll();
    uint add_LS_item();
    uint rm_LS_item();
};