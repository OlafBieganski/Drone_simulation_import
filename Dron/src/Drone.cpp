#include "../inc/Drone.hh"

using std::array;

Drone::Drone(Wektor<3> droneMiddle){
    
    Wektor<3> proppelerMid1={2,2,1.5}, proppelerMid2={5,2,1.5},
    proppelerMid3={5,5,1.5}, proppelerMid4={2,5,1.5};

    Prostopadloscian body(array<Wektor<3>,4>{{Wektor<3>{2,2,0},Wektor<3>{5,2,0},Wektor<3>{5,5,0},Wektor<3>{2,5,0}}},1);
    Hexagon3D proppeler1(proppelerMid1,2,0.5), proppeler2(proppelerMid2,2,0.5), proppeler3(proppelerMid3,2,0.5),
    proppeler4(proppelerMid4,2,0.5);

    const Wektor<3> initialMiddle={3.5,3.5,0.5};

    body.translacja(initialMiddle-droneMiddle);
    proppeler1.translation(initialMiddle-droneMiddle);
    proppeler2.translation(initialMiddle-droneMiddle);
    proppeler3.translation(initialMiddle-droneMiddle);
    proppeler4.translation(initialMiddle-droneMiddle);

    frame=body;
    rotors[0]=proppeler1;
    rotors[1]=proppeler2;
    rotors[2]=proppeler3;
    rotors[3]=proppeler4;
}


void Drone::draw(std::shared_ptr<drawNS::Draw3DAPI> api) const{
    frame.draw(api);
    for(int i=0;i<4;i++){
        rotors[i].draw(api);
    }
}