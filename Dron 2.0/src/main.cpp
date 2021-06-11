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


void listElems(std::vector<long int> IDs, std::vector<std::string> names, std::vector<Wektor<2>> place){
    
    if(IDs.empty()==false){
        for(uint i=0;i<IDs.size();i++){
            cout<<i+1<<". "<<names[i]
            <<"  "<<place[i]<<endl;
        }
    }
    else{
        cout<<"Brak obiektow"<<endl;
    }
}

void menu(){
    cout<<endl;
    cout<<"Dostepne opcje:"<<endl<<endl;
    cout<<"p - zadaj parametry przelotu."<<endl;
    cout<<"w - pokaz wspolrzedne drona."<<endl;
    cout<<"m - menu."<<endl;
    cout<<"u - usun element powierzchni."<<endl;
    cout<<"d - dodaj element powierzchni."<<endl;
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
    quadcopter.draw();
    plane.draw();

    Scene landscape(api);
    //landscape.add_LS_item("Plateau");
    //landscape.add_LS_item("PlateauC");
    //landscape.add_LS_item("Hill");
    //landscape.drawAll();
    //Wektor<2> x={20,20};
    //Hill h(x,6,api,"red");
    //h.showVert();
    //h.draw();
    menu();

    char choice, choice2;
    double height, distance, angle;
    std::vector<long int> IDs;
    std::vector<std::string> names;
    std::vector<Wektor<2>> place;
    Wektor<2> location;
    uint nr;
    while(1){
        cout<<endl<<"Ilosc wektorow utworzonych do tej pory: "<<Wektor<3>::get_Sum()<<endl;
        cout<<"Ilosc wektorow istniejacych aktualnie: "<<Wektor<3>::get_Now()<<endl;

        cout<<endl<<"Wybierz opcje: ";
        cin>>choice;
        cout<<endl;

        switch (choice)
        {
        case 'u':
            cout<<"Wybierz element do usuniecia:"<<endl;
            listElems(IDs,names,place);
            if(IDs.empty()==true) break;
            cin>>nr;
            try{
                landscape.rm_LS_item(IDs.at(nr-1));
            }
            catch(const std::out_of_range& oor){
                std::cerr << "Out of Range error: " << oor.what() << '\n';
                break;
            }
            IDs.erase(IDs.begin()+nr-1);
            place.erase(place.begin()+nr-1);
            names.erase(names.begin()+nr-1);
            break;

        case 'd':
            cout<<"Wybierz element do dodania:"<<endl;
            cout<<"Gora - 1"<<endl;
            cout<<"Plaskowyz - 2"<<endl;
            cout<<"Plaskowyz Prostopadloscienny - 3"<<endl;
            cin>>choice2;
            checkInput(choice2);
            cout<<"Podaj wspolrzedne obiektu (x,y): "<<endl;
            cin>>location;
            switch (choice2)
            {
            case '1':
                IDs.push_back(landscape.add_LS_item("Hill", location));
                names.push_back("Gora");
                place.push_back(location);
                break;
            case '2':
                IDs.push_back(landscape.add_LS_item("Plateau", location));
                names.push_back("Plaskowyz");
                place.push_back(location);
                break;
            case '3':
                IDs.push_back(landscape.add_LS_item("PlateauC", location));
                names.push_back("Plaskowyz Prostopadloscienny");
                place.push_back(location);
                break;
            default:
                break;
            }
            landscape.eraseAll();
            landscape.drawAll();
            break;
            

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