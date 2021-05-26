#include "../inc/Surface.hh"
#include <iostream>
#include "../inc/Wektor.hh"
#include "../inc/Hexagon3D.hh"
#include "../inc/Prostopadloscian.hh"
#include "../inc/Drone.hh"
#include "../inc/Scene.hh"


using std::cout;
using std::cin;
using std::endl;
using drawNS::APIGnuPlot3D;
using std::array;


void menu(){
    cout<<endl;
    cout<<"Dostepne opcje:"<<endl<<endl;
    cout<<"p - zadaj parametry przelotu."<<endl;
    cout<<"w - pokaz wspolrzedne drona."<<endl;
    cout<<"m - menu"<<endl;
    cout<<"k - koniec programu."<<endl;
    cout<<endl;
}

template<class T>
void checkInput(T storagePlace){
    while(!cin.good()){
        cin.clear();
        cin.ignore(1000, '\n');
        cout<<"Zly format. Wprowadz dane ponownie."<<endl;
        cin>>storagePlace;
    }
}

int main(){

    std::shared_ptr<drawNS::Draw3DAPI> api(new APIGnuPlot3D(0,40,0,40,0,20,0));
    Surface plane(0,api,"yellow");
    Wektor<3> v1={5,5,0.5}; //startowa pozycja drona
    Drone quadcopter(v1,api,"red");
    plane.draw();
    quadcopter.draw();

    Scene landscape(api);
    //landscape.add_LS_item("Plateau");
   // landscape.add_LS_item("PlateauC");
    landscape.add_LS_item("Hill");
    landscape.drawAll();

    menu();

    char choice;
    double height, distance, angle;
    while(1){
        cout<<endl<<"Ilosc wektorow utworzonych do tej pory: "<<Wektor<3>::get_Sum()<<endl;
        cout<<"Ilosc wektorow istniejacych aktualnie: "<<Wektor<3>::get_Now()<<endl;

        cout<<endl<<"Wybierz opcje: ";
        cin>>choice;
        cout<<endl;

        switch (choice)
        {
        case 'p':
            cout<<"Podaj kolejno wysokosc, odleglosc, i kat obrotu drona podczas lotu: ";
            cin>>height;
            checkInput(height);
            cin>>distance;
            checkInput(distance);
            cin>>angle;
            checkInput(angle);
            cout<<endl;
            quadcopter.animatedFly(angle,height, distance);
            break;

        case 'm':
            menu();
            break;
        
        case 'w':
            cout<<"Wspolrzedne srodka drona (x,y): ";
            cout<<quadcopter.getCoord()<<endl<<endl;
            break;

        case 'k':
            return 0;
        
        default:
            cout<<"Nierozpoznana opcja."<<endl<<endl;
            break;
        }
    }

    
    return 0;
}