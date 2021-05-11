#include "../inc/Surface.hh"
#include <iostream>
#include "../inc/Wektor.hh"
#include "../inc/Hexagon3D.hh"
#include "../inc/Prostopadloscian.hh"
#include "../inc/Drone.hh"


using std::cout;
using std::cin;
using std::endl;
using drawNS::APIGnuPlot3D;
using std::array;


void menu(){
    cout<<endl;
    cout<<"Dostepne opcje:"<<endl;
    cout<<"p - zadaj parametry przelotu."<<endl;
    cout<<"w - pokaz wspolrzedne drona."<<endl;
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

    Surface plane;
    std::shared_ptr<drawNS::Draw3DAPI> api(new APIGnuPlot3D(0,40,0,40,-1,20,0));
    Wektor<3> v1={5,5,0.5}; //startowa pozycja drona
    Drone quadcopter(v1);

    plane.draw(api, "yellow");
    quadcopter.draw(api);

    menu();

    char choice;
    double height, distance, angle;
    while(1){
        cout<<endl<<"Wybierz opcje: "<<endl;
        cin>>choice;
        checkInput(choice);
        cout<<endl;

        switch (choice)
        {
        case 'p':
            cout<<"Podaj kolejno wysokosc, odleglosc, i kat obrotu drona podczas lotu:"<<endl;
            cin>>height;
            checkInput(height);
            cin>>distance;
            checkInput(distance);
            cin>>angle;
            checkInput(angle);
            cout<<height<<"  "<<distance<<"  "<<angle<<endl;
            quadcopter.animatedFly(angle,height, distance, api);
            break;

        case 'm':
            menu();
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