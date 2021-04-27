#include "Prostopadloscian.hh"


/*Wierzcholki podajemy w kolejnosci:
-wiercholki podstawy
-wierzcholki gornej podstawy odpowiadajace dolnym*/
Prostopadloscian::Prostopadloscian(std::array<Wektor<3>, 4> podstawa, double wysokosc){
    Wektor<3> boki[4];
    boki[0]=podstawa[1]-podstawa[0];
    boki[1]=podstawa[2]-podstawa[1];
    boki[2]=podstawa[3]-podstawa[2];
    boki[3]=podstawa[0]-podstawa[3];
    if( (boki[0]!=boki[2]) || (boki[1]!=boki[3]) || boki[0]*boki[1]!=0 || boki[2]*boki[3]!=0){
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