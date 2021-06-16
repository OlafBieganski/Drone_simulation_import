#ifndef WEKTOR_HH
#define WEKTOR_HH

#include <iostream>
#include <vector>
#include <cmath>
#include <initializer_list>
#include <iomanip>

#define EPSILON 0.000001

template<unsigned int R>
class Wektor {
  private:
  std::vector<double> tab;
  inline static unsigned int quanNow=0;
  inline static unsigned int quanSum=0;
  public:
  static uint get_Sum() {return quanSum;}
  static uint get_Now() {return quanNow;}
  ~Wektor() {quanNow--;}
  Wektor() {for(unsigned int i=0;i<R;++i) tab.push_back(0.0);quanNow++;quanSum++;}
  Wektor(std::initializer_list<double> l): tab(l) {quanNow++;quanSum++;}
  Wektor(const Wektor<R> & newVec) {*this=newVec;quanNow++;quanSum++;}
  Wektor<R> operator + (const Wektor<R> & arg2) const;
  Wektor<R> operator - (const Wektor<R> & arg2) const;
  double operator * (const Wektor<R> & arg2) const;
  Wektor<R> operator * (const double & arg2) const;
  const double & operator [] (unsigned int ind) const;
  double & operator [] (unsigned int ind);
  bool operator == (const Wektor<R> & arg2) const;
  bool operator != (const Wektor<R> & arg2) const;
  double modul() const;
  Wektor<R> crossProduct(const Wektor<R> & v2);
};

template<unsigned int R>
Wektor<R> Wektor<R>::crossProduct(const Wektor<R> & v2){
    if(R!=3){
        std::cerr<<"Iloczyn wektorowy dostepny tylko dla 3D"<<std::endl;
        exit(1);
    }
}

template<unsigned int R>
Wektor<R> Wektor<R>::operator * (const double & arg2) const{
  Wektor<R> wynik;
  for(unsigned int i=0;i<R;i++){
    wynik[i]=tab[i]*arg2;
  }
  return wynik;
}


template<unsigned int R>
double Wektor<R>::modul() const{
  return sqrt((*this)*(*this));
}


template<unsigned int R>
Wektor<R>  Wektor<R>::operator + (const Wektor<R> & arg2) const{
    Wektor<R> wynik;
    for(unsigned int i=0;i<R;i++){
        wynik[i]=tab[i]+arg2[i];
    }
    return wynik;
}

template<unsigned int R>
Wektor<R>  Wektor<R>::operator - (const Wektor<R> & arg2) const{
    Wektor<R> wynik;
    for(unsigned int i=0;i<R;i++){
        wynik[i]=tab[i]-arg2[i];
    }
    return wynik;
}

template<unsigned int R>
double  Wektor<R>::operator * (const Wektor<R> & arg2) const{
    double wynik=0;
    for(unsigned int i=0;i<R;i++) wynik+=tab[i]*arg2[i];
    return wynik;
}

template<unsigned int R>
const double & Wektor<R>::operator [] (unsigned int ind) const{
    if(ind<R) return tab[ind];
    std::cerr<<"Blad indeksowania Wektor<R>."<<std::endl; 
    exit(1);
}

template<unsigned int R>
double & Wektor<R>::operator [] (unsigned int ind){
    if(ind<R) return tab[ind];
    std::cerr<<"Blad indeksowania Wektor<R>."<<std::endl; 
    exit(1);
}

template<unsigned int R>
std::ostream& operator << (std::ostream &Strm, const Wektor<R> &Wek){
    for(unsigned int i=0;i<R;++i){
    Strm<< std::setw(16) << std::fixed << std::setprecision(10)<< Wek[i];
    }
    return Strm;
}


template<unsigned int R>
bool Wektor<R>::operator == (const Wektor<R> & arg2) const{
    for(unsigned int i=0;i<R;++i){
        if(abs(arg2[i]-tab[i])>EPSILON) return false;
    }
    return true;
}

template<unsigned int R>
bool Wektor<R>::operator != (const Wektor<R> & arg2) const{
  if(*this==arg2) return false;
  return true;
}

template<unsigned int R>
std::istream& operator >> (std::istream &Strm, Wektor<R> &Wek){
    double a, z, x;
    char znak;

    if(R<2){
        std::cerr<<"Blad wczytywania Wektor<R>"<<std::endl;
        exit(1);
    }

    Strm>>znak;
    if(znak!='('){
        Strm.setstate(std::ios::failbit);
        return Strm;
    }
    Strm>>a;
    Wek[0]=a;
    Strm>>znak;
    if(znak!=','){
        Strm.setstate(std::ios::failbit);
        return Strm;
    }
    if(R>2){
        for(unsigned int i=1;i<(R-1);++i){
            Strm>>x;
            Wek[i]=x;
            Strm>>znak;
            if(znak!=','){
                Strm.setstate(std::ios::failbit);
                return Strm;
            }
        }
    }
    Strm>>z;
    Wek[R-1]=z;
    Strm>>znak;
    if(znak!=')'){
        Strm.setstate(std::ios::failbit);
        return Strm;
    }
    return Strm;
}



#endif
