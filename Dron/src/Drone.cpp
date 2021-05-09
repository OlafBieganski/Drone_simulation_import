#include "../inc/Drone.hh"

#define ROTORSQUAN 4 // ilosc wirnikow

using std::array;

// nalezy podac srodek drona
Drone::Drone(Wektor<3> droneMiddle){

    Prostopadloscian body(array<Wektor<3>,4>{{Wektor<3>{2,2,-0.5},Wektor<3>{2,-2,-0.5},Wektor<3>{-2,-2,-0.5},Wektor<3>{-2,2,-0.5}}},-1);

    Hexagon3D proppeler(Wektor<3>(),3,0.5);
    
    for(int i=0;i<ROTORSQUAN;i++) rotors[i]=proppeler;
    frame=body;

    frame.setCoord(droneMiddle, MacierzObr<3>(), this);
    
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

void Drone::flyUp(double height){

    Wektor<3> v={0,0,height};
    frame.translateSys(v);
  //  for(int i=0;i<ROTORSQUAN;i++){
  //      rotors[i].translateSys(v);
  //  }
}


void Drone::flyVert(double distance){
    
    Wektor<3> v={distance,0,0};
    frame.translateSys(v);
   // for(int i=0;i<ROTORSQUAN;i++){
   //     rotors[i].translateSys(v);
   // }
}


void Drone::turn(double angle_deg){

    MacierzObr<3> turn((angle_deg/180)*M_PI,"OZ");
    frame.rotateSys(turn);
}

void Drone::eraseDrone(std::shared_ptr<drawNS::Draw3DAPI> api){
    for(int i=0;i<5;i++){
        api->erase_shape(shapeID[i]);
    }
    for(int i=0;i<5;i++) shapeID.pop_back();
}