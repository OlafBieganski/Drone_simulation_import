#include "../inc/Prostokat.hh"
#include "../inc/Macierz2x2.hh"

#define EPSILON 0.000001

using drawNS::Point2D;
using drawNS::APIGnuPlot2D;

void Prostokat::rotacja(double kat_w_deg){
    Macierz2x2 matrix((kat_w_deg*3.14)/180);
    for(int i=0;i<4;i++){
    punkty[i]=matrix*this->punkty[i];
    }
}

Prostokat Prostokat::translacja(Wektor2D wek){
    Prostokat nowy;
    Wektor2D tmp;
    for(int i=0;i<4;i++){
    nowy.punkty[i]=this->punkty[i]+wek;
    }
    return nowy;
}

const Wektor2D & Prostokat::operator [] (unsigned int ind) const{
    if(ind<=3) return punkty[ind];
    std::cerr<<"Blad indeksowania obiekt 'Prostokat'."<<std::endl;
    exit(1);
}

void Prostokat::rysuj(drawNS::Draw2DAPI *rysownik){
    std::vector<Point2D> wspolrzede;
    for(int i=0;i<4;i++){
        wspolrzede.push_back(konwertuj(punkty[i]));
    }
    wspolrzede.push_back(konwertuj(punkty[0]));
    id_rysynku=rysownik->draw_polygonal_chain(wspolrzede, "red");
}

Prostokat::Prostokat(Wektor2D p1, Wektor2D p2, Wektor2D p3, Wektor2D p4){
    Wektor2D bok1, bok2, bok3, bok4;
    bok1=p2-p1;
    bok2=p3-p2;
    bok3=p3-p4;
    bok4=p4-p1;
    //std::cout<<bok1<<std::endl;
    //std::cout<<bok2<<std::endl;
    //std::cout<<bok3<<std::endl;
    //std::cout<<bok4<<std::endl;
    if( (bok1==bok3) && (bok2==bok4) && bok1*bok2==0 && bok3*bok4==0){
        punkty.push_back(p1);
        punkty.push_back(p2);
        punkty.push_back(p3);
        punkty.push_back(p4);
    }else{
    std::cerr<<"Bledna inicjalizacja obiektu 'Prostokat'."<<std::endl;
    exit(1);
    }
}

Prostokat::Prostokat(){
    Wektor2D w1;
    for(int i=0;i<4;i++) punkty.push_back(w1);
}