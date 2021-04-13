#include "../inc/Wektor2D.hh"
#include <iomanip>

#define EPSILON 0.000001

Wektor2D  Wektor2D::operator + (const Wektor2D & arg2) const{
    Wektor2D wynik;
    wynik[0]=xy[0]+arg2[0];
    wynik[1]=xy[1]+arg2[1];
    return wynik;
}

Wektor2D  Wektor2D::operator - (const Wektor2D & arg2) const{
    Wektor2D wynik;
    wynik[0]=xy[0]-arg2[0];
    wynik[1]=xy[1]-arg2[1];
    return wynik;
}

double  Wektor2D::operator * (const Wektor2D & arg2) const{
    return xy[0]*arg2[0]+xy[1]*arg2[1];
}

const double & Wektor2D::operator [] (int ind) const{
    if(ind==0 || ind==1) return xy[ind];
    std::cerr<<"Blad indeksowania Wektor2D."<<std::endl; 
    exit(1);
}

double & Wektor2D::operator [] (int ind){
    if(ind==0 || ind==1) return xy[ind];
    std::cerr<<"Blad indeksowania Wektor2D."<<std::endl; 
    exit(1);
}
std::ostream& operator << (std::ostream &Strm, const Wektor2D &Wek){
    Strm<< std::setw(16) << std::fixed << std::setprecision(10)<< Wek[0]
    << std::setw(16) << std::fixed << std::setprecision(10) <<Wek[1];
    return Strm;
}

drawNS::Point2D konwertuj(Wektor2D arg){
    return drawNS::Point2D(arg[0], arg[1]);
}

bool Wektor2D::operator == (const Wektor2D & arg2) const{
    return (abs(arg2[0]-xy[0])<EPSILON && abs(arg2[1]-xy[1])<EPSILON);
}

std::istream& operator >> (std::istream &Strm, Wektor2D &Wek){
    double x, y;
    char znak;

    Strm>>znak;
    if(znak!='('){
        Strm.setstate(std::ios::failbit);
        return Strm;
    }
    Strm>>x;
    Wek[0]=x;
    Strm>>znak;
    if(znak!=','){
        Strm.setstate(std::ios::failbit);
        return Strm;
    }
    Strm>>y;
    Wek[1]=y;
    Strm>>znak;
    if(znak!=')'){
        Strm.setstate(std::ios::failbit);
        return Strm;
    }
    return Strm;
}