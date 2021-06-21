#include "../inc/Scene.hh"
#include "../inc/Drone.hh"

using std::cin;
using std::cout;
using std::endl;

#define NOTDRAWN 10000 // jezli obiekt nie narysowany przyjmuje ta wartosc

void Scene::drawAll(){
    for(DrawingInterface* & x: toDraw){
        x->draw();
    }
}

void Scene::eraseAll(){
    for(DrawingInterface* & x: toDraw){
        if(x->getID()!=NOTDRAWN){
            api->erase_shape(x->getID());
        }
    }
}

long int Scene::add_LS_item(std::string name, Wektor<2> location){
    if(name=="Plateau"){
        std::string color;
        uint vertNr;
        cout<<"Podaj kolor obiektu (black, green, yellow, red, blue): "<<endl;
        cin>>color;
        cout<<"Podaj ilosc katow wielokata: "<<endl;
        cin>>vertNr;
        Plateau* p= new Plateau(location,vertNr,api,color); // czy tak jest ok?
        toDraw.push_back(p);
        return (long int)p; // zwaracamy id obiektu
    }
    if(name=="PlateauC"){
        std::string color;
        double h,l,w;
        cout<<"Podaj kolor obiektu (black, green, yellow, red, blue): "<<endl;
        cin>>color;
        cout<<"Podaj wysokosc (OZ): "<<endl;
        cin>>h;
        cout<<"Podaj szerokosc (OX): "<<endl;
        cin>>w;
        cout<<"Podaj dlugosc (OY): "<<endl;
        cin>>l;
        Plateau_Cuboid* pC = new Plateau_Cuboid(location,h,w,l,api,color);
        toDraw.push_back(pC);
        return (long int)pC; // zwaracamy id obiektu
    }
    if(name=="Hill"){
        std::string color;
        uint vertNr;
        cout<<"Podaj kolor obiektu (black, green, yellow, red, blue): "<<endl;
        cin>>color;
        cout<<"Podaj ilosc katow wielokata: "<<endl;
        cin>>vertNr;
        Hill* h = new Hill(location,vertNr,api,color);
        toDraw.push_back(h);
        return (long int)h; // zwaracamy id obiektu
    }
    if(name=="Drone"){
        std::string color;
        Wektor<3> middle={location[0],location[1],0.5};
        cout<<"Podaj kolor drona (black, green, yellow, red, blue): "<<endl;
        cin>>color;
        Drone* quadcopter = new Drone(middle,api,color);
        drones.push_back(quadcopter);
        toDraw.push_back(quadcopter);
        return (long int)quadcopter;
    }
    std::cerr<<"Blad: nie mozna stworzyc takiego elementu."<<endl;
    exit(1);
}

void Scene::rm_LS_item(long int id){
    for(auto it = toDraw.begin(); it != toDraw.end();){
        if((long int)(*it)==id){ // sprawdzamy czy id, ktore jest adresem zgadza sie z aktualnie sprawdzanym
            api->erase_shape((*it)->getID());
            toDraw.erase(it);
            it=toDraw.end();
        }
        else{
            ++it;
        }
    }
}

void Scene::listObjects() const {
    for(DrawingInterface* x: toDraw){
        cout<<"ShapeID: "<<x->getID()<<endl;
    }
    cout<<"Listing procedure finished"<<endl;
}

Wektor<2> Scene::flyDrone(uint nr, double angle, double height, double distance) const {
    drones.at(nr-1)->animatedFly(angle, height, distance);
    return drones.at(nr-1)->getCoord();
}

void Scene::rmDrone(long int id){
    for(auto it = drones.begin(); it != drones.end();){
        if((long int)(*it)==id){ // sprawdzamy czy id, ktore jest adresem zgadza sie z aktualnie sprawdzanym
            (*it)->eraseDrone();
            drones.erase(it);
            it=drones.end();
        }
        else{
            ++it;
        }
    }
}