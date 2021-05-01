#include "../inc/Wektor.hh"
#include "../inc/MacierzObr.hh"
#include "../inc/Prostopadloscian.hh"
#include "../API/source/Dr3D_gnuplot_api.hh"

using drawNS::Draw3DAPI;
using drawNS::APIGnuPlot3D;
using std::cout;
using std::cin;
using std::endl;

void porownajBoki(std::array<std::array<double,4>,3> krawedzie){
  int i;

  //liczymy srednia artytemtyczna zeby sprawdzic czy krawedzie rownej dlugosci
  if((krawedzie[0][0]+krawedzie[0][1]+krawedzie[0][2]+krawedzie[0][3])/4==krawedzie[0][0]){
    cout<<"Krotsze krawedzie podstawy sa rownej dlugosci."<<endl;
  }
  else{
    cout<<"Krotsze krawedzie podstawy sa roznej dlugosci."<<endl;
  }

  for(i=0;i<4;++i){
    cout<<"Dlugosc krawedzi nr "<<i+1<<" = "<<krawedzie[0][i]<<endl;
  }

  if((krawedzie[1][0]+krawedzie[1][1]+krawedzie[1][2]+krawedzie[1][3])/4==krawedzie[1][0]){
    cout<<"Dluzsze krawedzie podstawy sa rownej dlugosci."<<endl;
  }
  else{
    cout<<"Dluzsze krawedzie podstawy sa roznej dlugosci."<<endl;
  }

  for(i=0;i<4;++i){
    cout<<"Dlugosc krawedzi nr "<<i+1<<" = "<<krawedzie[1][i]<<endl;
  }

  if((krawedzie[2][0]+krawedzie[2][1]+krawedzie[2][2]+krawedzie[2][3])/4==krawedzie[2][0]){
    cout<<"Wysokosci prostopadloscianu sa rownej dlugosci."<<endl;
  }
  else{
    cout<<"Wysokosci prostopadloscianu sa roznej dlugosci."<<endl;
  }

  for(i=0;i<4;++i){
    cout<<"Dlugosc krawedzi nr "<<i+1<<" = "<<krawedzie[2][i]<<endl;
  }
}

void Menu(){
  cout<<"o - obrot prostokata o zadany kat"<<endl;
  cout<<"t - powtorzenie poprzedniego obrotu"<<endl;
  cout<<"r - wyswietlenie macierzy rotacji"<<endl;
  cout<<"p - przesuniecie prostokata o zadany wektor"<<endl;
  cout<<"w - wyswietlenie wspolrzednych wierzcholkow"<<endl;
  cout<<"s - sprawdzenie dlugosci przeciwleglych bokow"<<endl;
  cout<<"m - wyswietl menu"<<endl;
  cout<<"k - koniec dzialania programu"<<endl;
}

int main(){

  char wybor;
  double katDeg;
  int obroty;

  Wektor<3> punkty[4]={{1,1,0}, {2,1,0}, {2,3,0}, {1,3,0}};
  std::array<Wektor<3>, 4> podstawa;
  for(int i=0;i<4;++i){
    podstawa[i]=punkty[i];
  }

  std::shared_ptr<drawNS::Draw3DAPI> api(new APIGnuPlot3D(-5,5,-5,5,-5,5,1000));
  Prostopadloscian bryla(podstawa, 2.0);

  porownajBoki(bryla.dlugoscKrawedzi());
  Menu();

  return 0;
/*
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
  */
}
