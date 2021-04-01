#include <iostream>
#include <cstring>
#include <cassert>
#include "../inc/BazaTestu.hh"



BazaTestu::BazaTestu(std::string nazwa){
  otworzPlik(nazwa);
}

bool BazaTestu::otworzPlik(std::string nazwa){
  strmPlikuP.open(nazwa, std::fstream::in);

  if(strmPlikuP.is_open()){
    return true;
  }
  else{
    return false;
  }
}

bool BazaTestu::PobierzNastpnePytanie(WyrazenieZesp & Pytanie){
  strmPlikuP>>Pytanie;

  while(strmPlikuP.fail()){
    if(strmPlikuP.eof()){
      return false;
    }
    std::cout<<"Pominieto bledna formule."<<std::endl<<std::endl;
    strmPlikuP.clear();
    strmPlikuP.ignore(1000, '\n');
    strmPlikuP>>Pytanie;
  }

  return true;
}
