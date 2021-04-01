#include <iostream>
#include "../inc/BazaTestu.hh"
#include "../inc/LZespolona.hh"
#include "../inc/WyrazenieZesp.hh"
#include "../inc/Statystyki.hh"

using namespace std;


int main(int argc, char **argv)
{
  WyrazenieZesp   WyrZ_PytanieTestowe;
  LZespolona odpowiedz;
  BazaTestu Baza;
  Statystyki stat;

  if (argc < 2) {
    cout << endl;
    cout << " Brak nazwy pliku z testem" << endl << endl;
    return 1;
  }

  if (Baza.otworzPlik(argv[1]) == false){
    cout<<"Blad otwarcia pliku z testem."<<endl;
    return 1;
  }

  cout << endl;
  cout << " Start testu arytmetyki zespolonej: " << argv[1] << endl;
  cout << endl;

  while (Baza.PobierzNastpnePytanie(WyrZ_PytanieTestowe)) {

    if(!cin.good()){
    cin.clear();
    cin.ignore(100,'\n');
    }
    cout<<"Podaj wynik operacji: ";
    cout<<WyrZ_PytanieTestowe;
    cout<<"Twoja odpowiedz to: ";
    cin>>odpowiedz;

    stat.ustawSzansy(3);

    while(!cin.good() && stat.ileSzans()!=0){
      stat.minusSzansa();
      cin.clear();
      cin.ignore(100,'\n');
      cout<<"Zly format. Sprobuj jescze raz: ";
      cin>>odpowiedz;
    }

    if(stat.ileSzans()==0){
      cout<<"Bledna odpowiedz."<<endl;
      stat.dodajBledna();
      cout<<"Poprawna odpowiedz~: "<<WyrZ_PytanieTestowe.Oblicz()<<endl<<endl;
    }
    else{
      if(WyrZ_PytanieTestowe.Oblicz()==odpowiedz){
        cout<<"Poprawna odpowiedz."<<endl<<endl;
        stat.dodajPoprawna();
      }
      else{
        cout<<"Bledna odpowiedz."<<endl;
        stat.dodajBledna();
        cout<<"Poprawna odpowiedz: "<<WyrZ_PytanieTestowe.Oblicz()<<endl<<endl;
      }
    }
  }

  stat.pokazStatystyki();
  
  cout << endl;
  cout << " Koniec testu" << endl;
  cout << endl;

}
