#ifndef BAZATESTU_HH
#define BAZATESTU_HH

#include <fstream>
#include "WyrazenieZesp.hh"


class BazaTestu {
  private:
  std::fstream strmPlikuP;
  public:

  BazaTestu() {};
  BazaTestu(std::string nazwa);
  bool otworzPlik(std::string nazwa);
  bool PobierzNastpnePytanie(WyrazenieZesp & Pytanie);
};


#endif
