#include "../inc/Plateau_Cuboid.hh"

Plateau_Cuboid::Plateau_Cuboid(Wektor<2> location, double heightZ, double widthX, double lenghtY, std::shared_ptr<drawNS::Draw3DAPI> _api, std::string _color){
    
    Wektor<3> mid={location[0],location[1],0};
    Wektor<3> v1={widthX/2,lenghtY/2,0}, v2={widthX/2,-lenghtY/2,0},
        v3={-widthX/2,lenghtY/2,0}, v4={-widthX/2,-lenghtY/2,0}, h={0,0,heightZ};

    punkty[0]=mid+v1;
    punkty[1]=mid+v2;
    punkty[2]=mid+v4;
    punkty[3]=mid+v3;
    for(int i=0;i<4;i++) punkty[i+4]=punkty[i]+h;
    api=_api;
    color=_color;
    middle=Wektor<3>();
    orientation=MacierzObr<3>();
    parent=nullptr;
}