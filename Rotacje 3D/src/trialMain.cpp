#include <iostream>
#include "../inc/Wektor.hh"

int main(){
    Wektor<2> v1={1,1};
    Wektor<2> v_1{3,4};
    Wektor<3> v3={1,2,3};
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

    v3[4]=21;

    std::cout<<std::endl<<"--------------MACIERZ-----------------"<<std::endl;

    

    return 0;
}