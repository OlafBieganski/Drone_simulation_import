#ifndef MACIERZ_HH
#define MACIERZ_HH

#include <iostream>
#include "../inc/Wektor.hh"
#include <cmath>

template<unsigned int R>
class Macierz {
  private:
  std::vector<Wektor<R>> wiersze;
  public:
  Macierz();
  Macierz(double _katRad, std::string axis = "OZ");
  Macierz<R>  operator * (const Macierz<R> & arg2) const;
  Wektor<R>  operator * (const Wektor<R> & wektor) const;
  const Wektor<R> & operator [] (unsigned int id) const;
};


// std::ostream& operator << (std::ostream &Strm, const Macierz &Mac);

template<unsigned int R>
const Wektor<R> & Macierz<R>::operator [] (unsigned int id) const{
    if(id<R) return wiersze[id];
    std::cerr<<"Blad indeksowania Wektor<R>."<<std::endl; 
    exit(1);
}

template<unsigned int R>
Macierz<R>::Macierz(){
    if(R==2){
        Wektor<2> wierszG={1,0};
        Wektor<2> wierszD={0,1};
        wiersze.push_back(wierszG);
        wiersze.push_back(wierszD);
    }
    else if(R==3){
        Wektor<3> wierszG={1,0,0};
        Wektor<3> wierszS={0,1,0};
        Wektor<3> wierszD={0,0,1};
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
Macierz<R>::Macierz(double _katRad, std::string axis = "OZ"){
    switch(R){
        case 2:{
            Wektor<2> wierszG={cos(_katRad),-sin(_katRad)};
            Wektor<2> wierszD={sin(_katRad),cos(_katRad)};
            wiersze.push_back(wierszG);
            wiersze.push_back(wierszD);
            break;
        }
        case 3:{
            if(axis=="OZ"){
                Wektor<3> wierszG={cos(_katRad),-sin(_katRad),0};
                Wektor<3> wierszS={sin(_katRad),cos(_katRad),0};
                Wektor<3> wierszD={0,0,1};
                wiersze.push_back(wierszG);
                wiersze.push_back(wierszS);
                wiersze.push_back(wierszD);
            }
            else if(axis=="OY"){
                Wektor<3> wierszG={cos(_katRad),0,sin(_katRad)};
                Wektor<3> wierszS={0,1,0};
                Wektor<3> wierszD={-sin(_katRad),0,cos(_katRad)};
                wiersze.push_back(wierszG);
                wiersze.push_back(wierszS);
                wiersze.push_back(wierszD);
            }
            else if(axis=="OX"){
                Wektor<3> wierszG={1,0,0};
                Wektor<3> wierszS={0,cos(_katRad),-sin(_katRad)};
                Wektor<3> wierszD={0,sin(_katRad),cos(_katRad)};
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
Macierz<R>  Macierz<R>::operator * (const Macierz<R> & arg2) const{
    Macierz<R> wynik;
   for(int i=0;i<R;++i){
       for(int j=0;j<R;++j){
           wynik[i][j]=wiersze[]
       }
   }
}

template <unsigned int R>
Wektor<R>  Macierz<R>::operator * (const Wektor<R> & wektor) const{
    if(R==2){
        Wektor<2> wynik;
        wynik[0]=wektor*wiersze[0];
        wynik[1]=wektor*wiersze[1];
        return wynik;
    }
    else if(R==3){
        Wektor<3> wynik;
        wynik[0]=wektor*wiersze[0];
        wynik[1]=wektor*wiersze[1];
        wynik[2]=wektor*wiersze[2];
        return wynik;
    }
    else{
        std::cerr<<"Blad. Nie mozna wykonac operacji macierzy rozmiaru R."<<std::endl;
        exit(1);
    }
}
/*
std::ostream& operator << (std::ostream &Strm, const Macierz &Mac){
    Strm<<"| "<<cos(Mac.getAngle())<<'\t'<<-sin(Mac.getAngle())<<" |"<<std::endl;
    Strm<<"| "<<sin(Mac.getAngle())<<'\t'<<cos(Mac.getAngle())<<" |"<<std::endl;
    return Strm;
}
*/
#endif
