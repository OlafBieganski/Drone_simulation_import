#include "../inc/Drone.hh"
#include <thread>
#include <chrono>

#define ROTORSQUAN 4 // ilosc wirnikow
#define HALF_HEIGHT 0.5 // polowa wysokosci korpusu

using std::array;


// nalezy podac srodek drona
Drone::Drone(Wektor<3> droneMiddle){

    Prostopadloscian body(array<Wektor<3>,4>{{Wektor<3>{2,2,-0.5},Wektor<3>{2,-2,-0.5},Wektor<3>{-2,-2,-0.5},Wektor<3>{-2,2,-0.5}}},-1);

    Hexagon3D proppeler(Wektor<3>(),3,0.5);
    
    for(int i=0;i<ROTORSQUAN;i++) rotors[i]=proppeler;
    frame=body;

    Wektor<3> correction={0,0,0.1}; // w celu unikniecia wnikania drona w podloze po locie
    frame.setCoord(droneMiddle+correction, MacierzObr<3>(), this);
    
    MacierzObr<3> turn(M_PI/2, "OZ");
    Wektor<3> shift={2,2,0.75};

    for(int i=0;i<ROTORSQUAN;i++){
       rotors[i].setCoord(shift, MacierzObr<3>(), &frame);
       shift=turn*shift;
    }
}


void Drone::draw(std::shared_ptr<drawNS::Draw3DAPI> api){
    
    Prostopadloscian newFrame=frame.convert_to_parent();
    array<Hexagon3D, 4> newRotors;

    for(int i=0;i<ROTORSQUAN;i++){
        newRotors[i]=rotors[i].convert_to_granpa();
    }

    shapeID.push_back(newFrame.draw(api));
    for(int i=0;i<ROTORSQUAN;i++){
        shapeID.push_back(newRotors[i].draw(api));
    }
    
}

void Drone::flyHoriz(double height){

    Wektor<3> v={0,0,height};
    frame.translateSys(v);
}


void Drone::flyVert(double distance){
    
    Wektor<3> v={distance,0,0};
    frame.translateSys(frame.getOrient()*v);
}


void Drone::turn(double angle_deg){

    MacierzObr<3> turn((angle_deg/180)*M_PI,"OZ");
    frame.rotateSys(turn);
}

bool Drone::eraseDrone(std::shared_ptr<drawNS::Draw3DAPI> api){
    
    if(shapeID.empty()==true) return false;
    for(int i=0;i<5;i++){
        api->erase_shape(shapeID[i]);
    }
    for(int i=0;i<5;i++) shapeID.pop_back();
    return true;
}

void Drone::land(){

    double deltaH= frame.getMiddle()[2]-HALF_HEIGHT;
    this->flyHoriz(-deltaH);
}

void Drone::moveRotors(){

    MacierzObr<3> turn1((M_PI*20)/180, "OZ");
    MacierzObr<3> turn2(-(M_PI*20)/180, "OZ");
    rotors[0].rotateSys(turn1);
    rotors[1].rotateSys(turn2);
    rotors[2].rotateSys(turn1);
    rotors[3].rotateSys(turn2);
}

void Drone::animatedFly(double angle_deg, double height, double distance, std::shared_ptr<drawNS::Draw3DAPI> api){

    int i;

    for(i=0;i<height*10;i++){
        this->eraseDrone(api);
        this->flyHoriz(0.1);
        this->moveRotors();
        this->draw(api);
        std::this_thread::sleep_for(std::chrono::milliseconds(200));
    }
    
    double x=1;
    if(angle_deg<0) x=-1;
    for(i=0;i<abs(angle_deg);i++){
        this->eraseDrone(api);
        this->turn(x);
        this->moveRotors();
        this->draw(api);
        std::this_thread::sleep_for(std::chrono::milliseconds(200));
    }

    for(i=0;i<distance*10;i++){
        this->eraseDrone(api);
        this->flyVert(0.1);
        this->moveRotors();
        this->draw(api);
        std::this_thread::sleep_for(std::chrono::milliseconds(200));
    }

    for(i=0;i<height*10;i++){
        this->eraseDrone(api);
        this->flyHoriz(-0.1);
        this->moveRotors();
        this->draw(api);
        std::this_thread::sleep_for(std::chrono::milliseconds(200));
    }
}

Wektor<2> Drone::getCoord() const{

    Wektor<2> middle2D;
    middle2D[0]=frame.getMiddle()[0];
    middle2D[1]=frame.getMiddle()[1];
    return middle2D;
}