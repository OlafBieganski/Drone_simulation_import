#include "../inc/Statystyki.hh"
#include <iostream>


Statystyki::Statystyki(): poprawne(0), bledne(0), szansy(0) {}

unsigned int Statystyki::ileSzans() const{
  return szansy;
}

void Statystyki::minusSzansa(){
    if(szansy>0) szansy-=1;
}

void Statystyki::ustawSzansy(unsigned int ilosc){
    szansy=ilosc;
}

void Statystyki::dodajPoprawna(){
  poprawne+=1;
}

void Statystyki::dodajBledna(){
  bledne+=1;
}

void Statystyki::pokazStatystyki(){
  std::cout<<"Ilosc pytan: "<<poprawne+bledne<<std::endl;
  std::cout<<"Poprawnych odpowiedzi: "<<poprawne<<std::endl;
  std::cout<<"Blednych odpowiedzi: "<<bledne<<std::endl;
  std::cout<<"Procent poprawnych odpowiedzi: "<<(poprawne*100)/(poprawne+bledne)<<"%"<<std::endl;
}
