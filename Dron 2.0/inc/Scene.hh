#include "Drone.hh"
#include "LandscapeInterface.hh"
#include "Plateau.hh"
#include "Plateau_Cuboid.hh"
#include "Hill.hh"

using std::list;

class Scene{
    private:
    list<DrawingInterface*> toDraw;
    list<LandscapeInterface*> landscapeItem;
    std::shared_ptr<drawNS::Draw3DAPI> api;
    public:
    // parametry: api
    Scene(std::shared_ptr<drawNS::Draw3DAPI> _api): api(_api) {}
    void drawAll();
    long int add_LS_item(std::string name); // name -> PlateauC, Plateau, Hill
    void rm_LS_item(long int id);
};