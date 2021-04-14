#include "../inc/Wektor2D.hh"
#include "../inc/Macierz2x2.hh"
#include "../inc/Prostokat.hh"
#include "../API2D/source/Dr2D_gnuplot_api.hh"

using drawNS::APIGnuPlot2D;
using std::cout;
using std::cin;
using std::endl;


void porownajBoki(const Prostokat & rectangle){
  Wektor2D bok1, bok2, bok3, bok4;

  bok1=rectangle[1]-rectangle[0];
  bok2=rectangle[2]-rectangle[1];
  bok3=rectangle[2]-rectangle[3];
  bok4=rectangle[3]-rectangle[0];

  if(bok1==bok3){
    cout<<endl<<"Dluzsze przeciwlegle boki sa rownej dlugosci."<<endl;
  }
  else{
    cout<<"Dluzsze przeciwlegle boki nie sa rownej dlugosci."<<endl;
  }

  cout<<endl<<"Dlugosc pierwszego boku: "<<bok1.modul()<<endl;
  cout<<"Dlugosc drugiego boku: "<<bok3.modul()<<endl<<endl;

  if(bok2==bok4){
    cout<<"Krotsze przeciwlegle boki sa rownej dlugosci."<<endl;
  }
  else{
    cout<<"Krotsze przeciwlegle boki nie sa rownej dlugosci."<<endl;
  }
  
  cout<<endl<<"Dlugosc pierwszego boku: "<<bok2.modul()<<endl;
  cout<<"Dlugosc drugiego boku: "<<bok4.modul()<<endl<<endl;
}

void Menu(){
  cout<<"o - obrot prostokata o zadany kat"<<endl;
  cout<<"p - przesuniecie prostokata o zadany wektor"<<endl;
  cout<<"w - wyswietlenie wspolrzednych wierzcholkow"<<endl;
  cout<<"m - wyswietl menu"<<endl;
  cout<<"k - koniec dzialania programu"<<endl;
}

int main(){
  Wektor2D w1(1,1), w2(11,1), w3(11,6), w4(1,6), vector;
  Prostokat rectangle(w1,w2,w3,w4);
  char wybor;
  double katDeg;
  int obroty;
  drawNS::Draw2DAPI *rysownik=new APIGnuPlot2D(-15,15,-15,15,0);

  porownajBoki(rectangle);
  Menu();

  while(1){
    cout<<endl<<"Twoj wybor? (m - menu) > ";
    cin>>wybor;
    cout<<endl;

    switch(wybor){
      case 'o':
        cout<<"Podaj wartosc kata obrotu w stopniach"<<endl;
        cin>>katDeg;
        cout<<endl<<"Ile razy operacja obrotu ma byc powtorzona?"<<endl;
        cin>>obroty;
        cout<<endl;
        //rectangle=rectangle.rotacja(katDeg*obroty);
        for(int i=0;i<obroty;i++){
          rectangle.rotacja(katDeg);
          cout<<i<<endl;
        }
        rectangle.rysuj(rysownik);
        porownajBoki(rectangle);
        break;
      case 'p':
        cout<<"Wprowadz wspolrzedne wektora translacji w postaci (x,y)";
        cout<<endl;
        cin>>vector;
        while(!cin.good()){
          cin.clear();
          cin.ignore(1000, '\n');
          cout<<"Zly format. Wprowadz dane ponownie."<<endl;
          cin>>vector;
        }
        rectangle=rectangle.translacja(vector);
        rectangle.rysuj(rysownik);
        break;
      case 'w':
        cout<<rectangle[0]<<endl;
        cout<<rectangle[1]<<endl;
        cout<<rectangle[2]<<endl;
        cout<<rectangle[3]<<endl;
        break;
      case 'm':
        Menu();
        break;
      case 'k':
          delete rysownik;
          return 0;
      default:
        cout<<"Nierozpoznana opcja."<<endl;
        break;
    }
  }
}
