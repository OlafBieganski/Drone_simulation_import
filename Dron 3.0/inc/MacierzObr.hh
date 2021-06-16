#ifndef MACIERZOBR_HH
#define MACIERZOBR_HH

#include <iostream>
#include "Wektor.hh"
#include <cmath>

using std::cout;
using std::endl;

template<unsigned int R>
class MacierzObr {
  private:
  std::vector<Wektor<R>> wiersze;
  Wektor<R> & operator [] (unsigned int id);
  public:
  MacierzObr();
  MacierzObr(double _katRad, std::string axis="OZ");
  MacierzObr<R>  operator * (const MacierzObr<R> & arg2) const;
  Wektor<R>  operator * (const Wektor<R> & wektor) const;
  const Wektor<R> & operator [] (unsigned int id) const;
};

template<unsigned int R>
Wektor<R> & MacierzObr<R>::operator [] (unsigned int id){
    if(id<R) return wiersze[id];
    std::cerr<<"Blad indeksowania Wektor<R>."<<std::endl; 
    exit(1);
}

template<unsigned int R>
const Wektor<R> & MacierzObr<R>::operator [] (unsigned int id) const{
    if(id<R) return wiersze[id];
    std::cerr<<"Blad indeksowania Wektor<R>."<<std::endl; 
    exit(1);
}

template<unsigned int R>
MacierzObr<R>::MacierzObr(){
    if(R==2){
        Wektor<R> wierszG={1,0};
        Wektor<R> wierszD={0,1};
        wiersze.push_back(wierszG);
        wiersze.push_back(wierszD);
    }
    else if(R==3){
        Wektor<R> wierszG={1,0,0};
        Wektor<R> wierszS={0,1,0};
        Wektor<R> wierszD={0,0,1};
        wiersze.push_back(wierszG);
        wiersze.push_back(wierszS);
        wiersze.push_back(wierszD);
    }
    else{
        std::cerr<<"Nie mozna utworzyc macierzy rozmiaru R"<<std::endl;
        exit(1);
    }
}

template<unsigned int R>
MacierzObr<R>::MacierzObr(double _katRad, std::string axis){
    switch(R){
        case 2:{
            Wektor<R> wierszG={cos(_katRad),-sin(_katRad)};
            Wektor<R> wierszD={sin(_katRad),cos(_katRad)};
            wiersze.push_back(wierszG);
            wiersze.push_back(wierszD);
            break;
        }
        case 3:{
            if(axis=="OZ"){
                Wektor<R> wierszG={cos(_katRad),-sin(_katRad),0};
                Wektor<R> wierszS={sin(_katRad),cos(_katRad),0};
                Wektor<R> wierszD={0,0,1};
                wiersze.push_back(wierszG);
                wiersze.push_back(wierszS);
                wiersze.push_back(wierszD);
            }
            else if(axis=="OY"){
                Wektor<R> wierszG={cos(_katRad),0,sin(_katRad)};
                Wektor<R> wierszS={0,1,0};
                Wektor<R> wierszD={-sin(_katRad),0,cos(_katRad)};
                wiersze.push_back(wierszG);
                wiersze.push_back(wierszS);
                wiersze.push_back(wierszD);
            }
            else if(axis=="OX"){
                Wektor<R> wierszG={1,0,0};
                Wektor<R> wierszS={0,cos(_katRad),-sin(_katRad)};
                Wektor<R> wierszD={0,sin(_katRad),cos(_katRad)};
                wiersze.push_back(wierszG);
                wiersze.push_back(wierszS);
                wiersze.push_back(wierszD);
            }
            break;
        }
        default:
        std::cerr<<"Blad. Nie mozna utworzyc macierzy rozmiaru R."<<std::endl;
        exit(1);
    }
}

template <unsigned int R>
MacierzObr<R>  MacierzObr<R>::operator * (const MacierzObr<R> & arg2) const{
    MacierzObr<R> wynik;
    double s;
   for(unsigned int i=0;i<R;++i){
       for(unsigned int j=0;j<R;++j){
           s=0;
           for(unsigned int k=0;k<R;++k){
               s+=(*this)[i][k]*arg2[k][j];
           }
           wynik[i][j]=s;
       }
   }
   return wynik;
}


template <unsigned int R>
Wektor<R>  MacierzObr<R>::operator * (const Wektor<R> & wektor) const{
    Wektor<R> wynik;
    for(unsigned int i=0;i<R;++i){
        wynik[i]=wektor*wiersze[i];
    }
    return wynik;
}

template <unsigned int R>
std::ostream& operator << (std::ostream &Strm, const MacierzObr<R> &Mac){
    for(unsigned int i=0;i<R;++i){
        Strm<<Mac[i]<<std::endl;
    }
    return Strm;
}

#endif
