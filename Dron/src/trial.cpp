#include "../inc/Surface.hh"
#include <iostream>
#include "../inc/Wektor.hh"
#include "../inc/Hexagon3D.hh"
#include "../inc/Prostopadloscian.hh"
#include "../inc/Drone.hh"


using std::cout;
using std::endl;
using drawNS::APIGnuPlot3D;
using std::array;


void wait(){
    {cout<<"Press an Enter to continue..."<<endl;}while(std::cin.get() != '\n');
}

int main(){
    array<Wektor<3>, 4> points={Wektor<3>{1,1,0},Wektor<3>{1,5,0},Wektor<3>{7,5,0},Wektor<3>{7,1,0}};
    Wektor<3> middle={1,1,3.5};
    Surface plane;
    Hexagon3D prism(middle,2.5,1.0);
    Prostopadloscian quboid(points, -3.0);

    std::shared_ptr<drawNS::Draw3DAPI> api(new APIGnuPlot3D(0,50,0,50,0,30,0));

    Wektor<3> v1={5,5,0.5}, v2={20,30,10};

    plane.draw(api, "yellow");
    /*  prism.translation(v2);
    quboid.translacja(v2);
    prism.rotation(MacierzObr<3>(M_PI/6,"OZ"));
    quboid.rotacja(MacierzObr<3>(M_PI/6,"OZ"));
    prism.draw(api);
    quboid.draw(api);*/

    Drone quadcopter(v1);
    quadcopter.draw(api);
    wait();

    quadcopter.animatedFly(83,14,21,api);

    wait();

    /*quadcopter.eraseDrone(api);
    quadcopter.flyHoriz(10);
    quadcopter.draw(api);
    wait();
    quadcopter.eraseDrone(api);
    quadcopter.turn(45);
    quadcopter.draw(api);
    wait();
    quadcopter.eraseDrone(api);
    quadcopter.flyVert(10);
    quadcopter.draw(api);
    wait();
    quadcopter.eraseDrone(api);
    quadcopter.flyVert(20);
    quadcopter.draw(api);
    wait();
    quadcopter.eraseDrone(api);
    quadcopter.turn(100);
    quadcopter.draw(api);
    wait();
    quadcopter.eraseDrone(api);
    quadcopter.flyVert(17);
    quadcopter.draw(api);
    wait();
    quadcopter.eraseDrone(api);
    quadcopter.land();
    quadcopter.draw(api);
    wait();*/
    
    return 0;
}