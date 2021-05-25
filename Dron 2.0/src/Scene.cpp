#include "../inc/Scene.hh"

using std::cin;
using std::cout;
using std::endl;

void Scene::drawAll(){
    for(DrawingInterface* & x: toDraw){
        x->draw();
    }
}

uint Scene::add_LS_item(std::string name){
    if(name=="Plateau"){
        Wektor<2> location;
        std::string color;
        uint vertNr;
        cout<<"Podaj wspolrzedne obiektu (x,y): "<<endl;
        cin>>location;
        cout<<"Podaj kolor obiektu (black, green, yellow, red, blue): "<<endl;
        cin>>color;
        cout<<"Podaj ilosc katow wielokata: "<<endl;
        cin>>vertNr;
        Plateau p(location,vertNr,api,color);
        toDraw.push_back(&p);
        return (uint)&p; // zwaracamy id obiektu
    }
    if(name=="PlateauC"){
        Wektor<2> location;
        std::string color;
        double h,l,w;
        cout<<"Podaj wspolrzedne obiektu (x,y): "<<endl;
        cin>>location;
        cout<<"Podaj kolor obiektu (black, green, yellow, red, blue): "<<endl;
        cin>>color;
        cout<<"Podaj wysokosc (OZ): "<<endl;
        cin>>h;
        cout<<"Podaj szerokosc (OX): "<<endl;
        cin>>w;
        cout<<"Podaj dlugosc (OY): "<<endl;
        cin>>l;
        Plateau_Cuboid pC(location,h,w,l,api,color);
        toDraw.push_back(&pC);
        return (uint)&pC; // zwaracamy id obiektu
    }
    if(name=="Hill"){
        Wektor<2> location;
        std::string color;
        uint vertNr;
        cout<<"Podaj wspolrzedne obiektu (x,y): "<<endl;
        cin>>location;
        cout<<"Podaj kolor obiektu (black, green, yellow, red, blue): "<<endl;
        cin>>color;
        cout<<"Podaj ilosc katow wielokata: "<<endl;
        cin>>vertNr;
        Hill h(location,vertNr,api,color);
        toDraw.push_back(&h);
        return (uint)&h; // zwaracamy id obiektu
    }
    std::cerr<<"Blad: nie mozna stworzyc takiego elementu."<<endl;
    exit(1);
}

void Scene::rm_LS_item(uint id){
    for(auto it = toDraw.begin(); it != toDraw.end();){
        if((uint)(*it)==id){ // sprawdzamy czy id, ktore jest adresem zgadza sie z aktualnie sprawdzanym
            api->erase_shape((*it)->getID());
            it=toDraw.erase(it);
        }
        else{
            ++it;
        }
    }
}