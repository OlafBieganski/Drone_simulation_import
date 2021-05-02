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

  cout.precision(17);

  //liczymy srednia artytemtyczna zeby sprawdzic czy krawedzie rownej dlugosci
  if((krawedzie[0][0]+krawedzie[0][1]+krawedzie[0][2]+krawedzie[0][3])/4.0==krawedzie[0][0]){
    cout<<"Krotsze krawedzie podstawy sa rownej dlugosci."<<endl;
  }
  else{
    cout<<"Krotsze krawedzie podstawy sa roznej dlugosci."<<endl;
  }

  for(i=0;i<4;++i){
    cout<<"Dlugosc krawedzi nr "<<i+1<<" = "<<std::fixed<<krawedzie[0][i]<<endl;
  }

  if((krawedzie[1][0]+krawedzie[1][1]+krawedzie[1][2]+krawedzie[1][3])/4.0==krawedzie[1][0]){
    cout<<"Dluzsze krawedzie podstawy sa rownej dlugosci."<<endl;
  }
  else{
    cout<<"Dluzsze krawedzie podstawy sa roznej dlugosci."<<endl;
  }

  for(i=0;i<4;++i){
    cout<<"Dlugosc krawedzi nr "<<i+1<<" = "<<std::fixed<<krawedzie[1][i]<<endl;
  }

  if((krawedzie[2][0]+krawedzie[2][1]+krawedzie[2][2]+krawedzie[2][3])/4.0==krawedzie[2][0]){
    cout<<"Wysokosci prostopadloscianu sa rownej dlugosci."<<endl;
  }
  else{
    cout<<"Wysokosci prostopadloscianu sa roznej dlugosci."<<endl;
  }

  for(i=0;i<4;++i){
    cout<<"Dlugosc krawedzi nr "<<i+1<<" = "<<std::fixed<<krawedzie[2][i]<<endl;
  }
}

void Menu(){
  cout<<"o - obrot prostokata o zadany kat"<<endl;
  cout<<"t - powtorzenie poprzedniego obrotu"<<endl;
  cout<<"r - wyswietlenie macierzy rotacji"<<endl;
  cout<<"p - przesuniecie prostokata o zadany wektor"<<endl;
  cout<<"w - wyswietlenie wspolrzednych wierzcholkow"<<endl;
  cout<<"s - sprawdzenie dlugosci przeciwleglych bokow"<<endl;
  cout<<"d - rysyj figure w gnuplocie"<<endl;
  cout<<"m - wyswietl menu"<<endl;
  cout<<"k - koniec dzialania programu"<<endl;
}

int main(){

  char wybor;
  std::array<double,3> katDeg={0,0,0};
  int obroty=0, i;
  Wektor<3> przesuniecie;
  MacierzObr<3> macierzRotacji;

  Wektor<3> punkty[4]={{1,1,0}, {2,1,0}, {2,3,0}, {1,3,0}};
  std::array<Wektor<3>, 4> podstawa;
  for(int i=0;i<4;++i){
    podstawa[i]=punkty[i];
  }

  std::shared_ptr<drawNS::Draw3DAPI> api(new APIGnuPlot3D(-5,5,-5,5,-5,5,0));
  Prostopadloscian bryla(podstawa, 2.5);

  porownajBoki(bryla.dlugoscKrawedzi());
  Menu();

  while(1){
    cout<<endl<<"Twoj wybor? (m - menu) > ";
    cin>>wybor;
    cout<<endl;

    switch(wybor){
      case 'o':{
        cout<<"Podaj katy obrotu w stopniach kolejno dla kazdej osi (0 = brak obrot):"<<endl;
        cout<<"OX: "; cin>>katDeg[0]; cout<<endl;
        cout<<"OY: "; cin>>katDeg[1]; cout<<endl;
        cout<<"OZ: "; cin>>katDeg[2]; cout<<endl;
        cout<<endl<<"Ile razy operacja obrotu ma byc powtorzona?"<<endl;
        cin>>obroty;
        cout<<endl;
        MacierzObr<3> macierzX((katDeg[0]*M_PI)/180.0, "OX");
        MacierzObr<3> macierzY((katDeg[1]*M_PI)/180.0, "OY");
        MacierzObr<3> macierzZ((katDeg[2]*M_PI)/180.0, "OZ");
        macierzRotacji=macierzX*macierzY*macierzZ;
        for(int i=0;i<obroty;i++){
          bryla.rotacja(macierzRotacji);
        }
        bryla.rysuj(api);
        porownajBoki(bryla.dlugoscKrawedzi());
        break;
      }
      case 'p':
        cout<<"Wprowadz wspolrzedne wektora translacji w postaci (x,y,z)";
        cout<<endl;
        cin>>przesuniecie;
        while(!cin.good()){
          cin.clear();
          cin.ignore(1000, '\n');
          cout<<"Zly format. Wprowadz dane ponownie."<<endl;
          cin>>przesuniecie;
        }
        bryla.translacja(przesuniecie);
        bryla.rysuj(api);
        break;
      case 'w':
        for(i=0;i<8;i++){
          cout<<bryla[i]<<endl;
        }
        break;
      case 'm':
        Menu();
        break;
      case 't':
        for(int i=0;i<obroty;++i){
          bryla.rotacja(macierzRotacji);
        }
        bryla.rysuj(api);
        porownajBoki(bryla.dlugoscKrawedzi());
        break;
      case 'r':
        cout<<macierzRotacji<<endl;
        break;
      case 's':
        porownajBoki(bryla.dlugoscKrawedzi());
        break;
      case 'd':
        bryla.rysuj(api);
        break;
      case 'k':
        return 0;
      default:
        cout<<"Nierozpoznana opcja."<<endl;
        break;
    }
  }
}
