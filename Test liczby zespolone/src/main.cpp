#include <iostream>
#include "../inc/BazaTestu.hh"
#include "../inc/LZespolona.hh"
#include "../inc/WyrazenieZesp.hh"

using namespace std;


int main(int argc, char **argv)
{

  if (argc < 2) {
    cout << endl;
    cout << " Brak opcji okreslajacej rodzaj testu." << endl;
    cout << " Dopuszczalne nazwy to:  latwy, trudny." << endl;
    cout << endl;
    return 1;
  }


  BazaTestu   BazaT = { nullptr, 0, 0 };

  if (InicjalizujTest(&BazaT,argv[1]) == false) {
    cerr << " Inicjalizacja testu nie powiodla sie." << endl;
    return 1;
  }


  
  cout << endl;
  cout << " Start testu arytmetyki zespolonej: " << argv[1] << endl;
  cout << endl;

  WyrazenieZesp   WyrZ_PytanieTestowe;
  LZespolona odpowiedz;
  unsigned int szansy=0;

  while (PobierzNastpnePytanie(&BazaT,&WyrZ_PytanieTestowe)) {

    cout<<"Podaj wynik operacji: ";
    Wyswietl(WyrZ_PytanieTestowe);
    cout<<"Twoja odpowiedz to: ";
    cin>>odpowiedz;

    while(!cin.good() && ileSzans(szansy)<4){
      cin.clear();
      cin.ignore(100,'\n');
      cout<<"Zly format. Sprobuj jescze raz: ";
      cin>>odpowiedz;
    }

    if(szansy==4){
      cout<<"Bledna odpowiedz."<<endl;
      cout<<"Poprawna odpowiedz~: "<<Oblicz(WyrZ_PytanieTestowe)<<endl<<endl;
    }
    else{
      if(Oblicz(WyrZ_PytanieTestowe)==odpowiedz){
        cout<<"Poprawna odpowiedz."<<endl<<endl;
        dodajPoprawna(&BazaT);
      }
      else{
        cout<<"Bledna odpowiedz."<<endl;
        cout<<"Poprawna odpowiedz: "<<Oblicz(WyrZ_PytanieTestowe)<<endl<<endl;
      }
    }

    zerujSzansy(szansy);
  }

  pokazStatystyki(BazaT);
  
  cout << endl;
  cout << " Koniec testu" << endl;
  cout << endl;

}
