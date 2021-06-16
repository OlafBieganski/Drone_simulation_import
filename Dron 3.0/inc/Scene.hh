#include "Drone.hh"
#include "LandscapeInterface.hh"
#include "Plateau.hh"
#include "Plateau_Cuboid.hh"
#include "Hill.hh"

using std::list;

class Scene{
    private:
    std::vector<Drone*> drones;
    list<DrawingInterface*> toDraw;
    list<LandscapeInterface*> landscapeItem;
    std::shared_ptr<drawNS::Draw3DAPI> api;
    public:
    // parametry: api
    Scene(std::shared_ptr<drawNS::Draw3DAPI> _api): api(_api) {}
    void drawAll();
    long int add_LS_item(std::string name, Wektor<2> location); // name -> PlateauC, Plateau, Hill
    void rm_LS_item(long int id);
    void listObjects() const;
    void eraseAll();
    Wektor<2> flyDrone(uint nr, double angle, double height, double distance) const;
    void rmDrone(long int id);
};