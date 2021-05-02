#include <iostream>
#include "../inc/Wektor.hh"
#include "../inc/MacierzObr.hh"
#include "../inc/Prostopadloscian.hh"
#include "../API/source/Dr3D_gnuplot_api.hh"

using std::endl;
using std::cout;

void wait4key() {
  do {
    std::cout << "\n Press a key to continue..." << std::endl;
  } while(std::cin.get() != '\n');
}

int main(){
 /*   
    Wektor<2> v1={1,1};
    Wektor<2> v_1{3,4};
    Wektor<3> v4={1,2,1};
    Wektor<6> v6, v({2,2,2,2,2,2});

    for(int i=0;i<6;++i){
        std::cout<<v6[i]<<std::endl;
    }

    v4=v3-v4;
    std::cout<<"V4: "<<v4<<std::endl;

    double x=v3*v4;
    std::cout<<"V3*V4: "<<x<<std::endl;

    v4=v3+v4;
    std::cout<<"V4: "<<v4<<std::endl;
    
    std::cin>>v6;
    std::cout<<"V6: "<<v6<<std::endl;

    double modul=v6.modul();
    std::cout<<"|V6|: "<<modul<<std::endl;

    v1[0]=3.4; v1[1]=4.5;
    v_1=v1+v_1;
    std::cout<<"V_1: "<<v_1<<std::endl;

*/
    std::cout<<std::endl<<"--------------MACIERZ-----------------"<<std::endl;
    
    Wektor<3> v3={4,2,3};
    MacierzObr<3> matrix3(M_PI*0.5, "OZ");
    MacierzObr<3> matrix4(M_PI*0.25, "OY");
    MacierzObr<3> matrix5(M_PI*(1.0/6.0), "OX");

    std::cout<<M_PI*(1.0/6.0)<<std::endl;

    std::cout<<"Macierz dla 90deg: "<<std::endl<<matrix3<<std::endl;
    std::cout<<"Macierz dla 45deg: "<<std::endl<<matrix4<<std::endl;
    std::cout<<"Macierz dla 30deg: "<<std::endl<<matrix5<<std::endl;

    matrix3=matrix5*matrix4;
    std::cout<<"Macierz po pierwszym mnozeniu: "<<std::endl<<matrix3<<std::endl;

    matrix3=matrix4*matrix5;
    std::cout<<"Macierz po drugim mnozeniu: "<<std::endl<<matrix3<<std::endl;


/*
    std::cout<<std::endl<<"--------------QUBOID-----------------"<<std::endl;

    Wektor<3> punkty[4]={{-1,1,0}, {1,1,0}, {1,-1,0}, {-1,-1,0}};
    std::array<Wektor<3>, 4> podstawa;
    for(int i=0;i<4;++i){
        podstawa[i]=punkty[i];
    }

    drawNS::Draw3DAPI * api = new drawNS::APIGnuPlot3D(-20,20,-20,20,-20,20,0);
    Prostopadloscian quboid(podstawa, 1.0);
    quboid.rysuj(api);
    
    wait4key();
    
    delete api;
    */
    return 0;
}