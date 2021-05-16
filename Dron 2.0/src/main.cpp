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

void drawAll(std::vector<DrawingInterface*> objects){
    for(DrawingInterface* & x: objects){
        x->draw();
        cout<<"Drawing successful."<<endl;
    }
}

int main(){

    std::shared_ptr<drawNS::Draw3DAPI> api(new APIGnuPlot3D(0,40,0,40,0,20,0));
    Surface plane(0,api,"yellow");
    Wektor<3> v1={5,5,0.5}; //startowa pozycja drona
    Drone quadcopter(v1,api,"red");
    Prostopadloscian obstacle1(std::array<Wektor<3>,4>{{Wektor<3>{4,8,0},Wektor<3>{8,8,0},Wektor<3>{8,12,0},Wektor<3>{4,12,0}}},5,api,"yellow");
    Wektor<3> v2={10,17,0};
    obstacle1.translacja(v2);

    std::vector<DrawingInterface*> objects;
    objects.push_back(&plane);
    objects.push_back(&quadcopter);
    objects.push_back(&obstacle1);
    drawAll(objects);

  /*  plane.draw();
    quadcopter.draw();
    obstacle1.draw();*/

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