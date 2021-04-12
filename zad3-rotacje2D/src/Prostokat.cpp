#include "../inc/Prostokat.hh"
#include "../inc/Macierz2x2.hh"

#define EPSILON 0.000001

using drawNS::Point2D;
using drawNS::APIGnuPlot2D;

Prostokat Prostokat::rotacja(double kat_w_deg) const{
    Macierz2x2 matrix(kat_w_deg);
    Prostokat nowy;
    for(int i=0;i<3;i++){
    nowy.punkty[i]=matrix*this->punkty[i];
    }
    return nowy;
}

Prostokat Prostokat::translacja(Wektor2D wek){
    Prostokat nowy;
    for(int i=0;i<3;i++){
    nowy.punkty[i]=this->punkty[i]+wek;
    }
    return nowy;
}

const Wektor2D & Prostokat::operator [] (unsigned int ind) const{
    if(ind<=3) return punkty[ind];
    std::cerr<<"Blad indektowania obiekt 'Prostokat'.";
    exit(1);
}

void Prostokat::rysuj(drawNS::Draw2DAPI *rysownik){
    std::vector<Point2D> wspolrzede;
    for(int i=0;i<3;i++){
        wspolrzede.push_back(konwertuj(punkty[i]));
    }
    id_rysynku=rysownik->draw_polygonal_chain(wspolrzede, "red");
}

Prostokat::Prostokat(Wektor2D p1, Wektor2D p2, Wektor2D p3, Wektor2D p4){
    if( (p2-p1==p4-p3) && (p3-p2==p1-p4) && (p2-p1)*(p3-p2)==0 && (p4-p3)*(p1-p4)==0){
        punkty[0]=p1; punkty[1]=p2; punkty[2]=p3; punkty[3]=p4;
    }
    std::cerr<<"Bledna inicjalizacja obiektu 'Prostokat'.";
    exit(1);
}

Prostokat::Prostokat(){
    Wektor2D w1;
    for(int i=0;i<3;i++) punkty[i]=w1;
}