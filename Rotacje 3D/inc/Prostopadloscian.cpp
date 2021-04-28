#include "Prostopadloscian.hh"


using drawNS::Point3D;
using drawNS::APIGnuPlot3D;
using std::vector;

Point3D konwertuj(Wektor<3> punkt){
    return Point3D(punkt[0],punkt[1],punkt[2]);
}

void Prostopadloscian::rysuj(drawNS::Draw3DAPI *rysownik){
    vector<Point3D> points1;
    vector<vector<Point3D>> points2;
    for(int i=0;i<8;++i){
        points1.push_back(konwertuj(punkty[i]));
    }
    points2.push_back(points1);
    rysownik->draw_polyhedron(points2);
    std::cout<<"halo"<<std::endl;
}


Prostopadloscian::Prostopadloscian(std::array<Wektor<3>, 4> podstawa, double wysokosc){
    Wektor<3> boki[4];
    boki[0]=podstawa[1]-podstawa[0];
    boki[1]=podstawa[2]-podstawa[1];
    boki[2]=podstawa[3]-podstawa[2];
    boki[3]=podstawa[0]-podstawa[3];
    double dlugoscBoku[4];
    for(int i=0;i<4;++i) dlugoscBoku[i]=boki[i].modul();
    for(int i=0;i<4;++i) std::cout<<dlugoscBoku[i]<<std::endl;
    if( !((dlugoscBoku[0]==dlugoscBoku[2]) && (dlugoscBoku[1]==dlugoscBoku[3]) && boki[0]*boki[1]==0 && boki[2]*boki[3]==0)){
        std::cerr<<"To nie jest prostopadloscian."<<std::endl;
        exit(1);
    }
    Wektor<3> wektorNormalny;
    Wektor<3> X={1,0,0}, Y={0,1,0}, Z={0,0,1};
    
    // iloczyn skalarany
    wektorNormalny=wektorNormalny+(Z*(boki[0][0]*boki[1][1]));
    wektorNormalny=wektorNormalny+(X*(boki[0][1]*boki[1][2]));
    wektorNormalny=wektorNormalny+(Y*(boki[0][2]*boki[1][0]));
    wektorNormalny=wektorNormalny-(X*(boki[0][2]*boki[1][1]));
    wektorNormalny=wektorNormalny-(Y*(boki[0][0]*boki[1][2]));
    wektorNormalny=wektorNormalny-(Z*(boki[0][1]*boki[1][0]));

    wektorNormalny=wektorNormalny*wysokosc;

    Wektor<3> gornapodstawa[4];

    for(int i=0;i<4;++i){
        gornapodstawa[i]=podstawa[i]+wektorNormalny;
    }

    for(int i=0;i<4;++i){
        punkty[i]=podstawa[i];
        punkty[i+4]=gornapodstawa[i];
    }

}


const Wektor<3> Prostopadloscian::operator [] (unsigned int ind) const{
    if(ind<7) return punkty[ind];
    std::cerr<<"Blad indeksowania obiektu Prostopadloscian."<<std::endl; 
    exit(1);
}

void Prostopadloscian::translacja(Wektor<3> przesuniecie){
    for(int i=0;i<8;++i){
        punkty[i]=punkty[i]+przesuniecie;
    }
}


void Prostopadloscian::rotacja(double katwRad, std::string axis){
    MacierzObr<3> obrot(katwRad, axis);

    for(int i=0;i<8;++i){
        punkty[i]=obrot*punkty[i];
    }
}