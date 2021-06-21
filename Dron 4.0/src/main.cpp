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

void listDrones(std::vector<std::string> droneNames, std::vector<Wektor<2>> droneLoc){
    if(droneNames.empty()==false){
        for(uint i=0;i<droneNames.size();i++){
            cout<<i+1<<". "<<droneNames[i]
            <<"  "<<droneLoc[i]<<endl;
        }
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
    plane.draw();

    Scene landscape(api);

    menu();

    char choice, choice2;
    double height, distance, angle;
    std::vector<long int> IDs;
    std::vector<std::string> names;
    std::vector<Wektor<2>> place;
    Wektor<2> location;
    std::string droneName;
    std::vector<std::string> droneNameArr;
    std::vector<long int> droneIDArr;
    std::vector<Wektor<2>> droneLocArr;
    uint nr;

    cout<<"Podaj wspolrzene srodka domyslnego drona (x,y): "<<endl;
    cin>>location;
    cout<<"Podaj nazwe drona: "<<endl;
    cin>>droneName;
    long int id=landscape.add_LS_item("Drone",location);
    IDs.push_back(id);
    names.push_back(droneName);
    place.push_back(location);
    droneNameArr.push_back(droneName);
    droneLocArr.push_back(location);
    droneIDArr.push_back(id);
    landscape.drawAll();

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
                landscape.rmDrone(IDs.at(nr-1));
            }
            catch(const std::out_of_range& oor){
                std::cerr << "Out of Range error: " << oor.what() << '\n';
                break;
            }
            IDs.erase(IDs.begin()+nr-1);
            place.erase(place.begin()+nr-1);
            names.erase(names.begin()+nr-1);
            droneIDArr.erase(droneIDArr.begin()+nr-1);
            droneLocArr.erase(droneLocArr.begin()+nr-1);
            droneNameArr.erase(droneNameArr.begin()+nr-1);
            break;

        case 'd':
            cout<<"Wybierz element do dodania:"<<endl;
            cout<<"Gora - 1"<<endl;
            cout<<"Plaskowyz - 2"<<endl;
            cout<<"Plaskowyz Prostopadloscienny - 3"<<endl;
            cout<<"Nowy dron - 4"<<endl;
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
            case '4':
                id=landscape.add_LS_item("Drone", location);
                IDs.push_back(id);
                cout<<"Podaj nazwe drona: "<<endl;
                cin>>droneName;
                names.push_back(droneName);
                place.push_back(location);
                droneNameArr.push_back(droneName);
                droneLocArr.push_back(location);
                droneIDArr.push_back(id);
                break;
            default:
                break;
            }
            landscape.eraseAll();
            landscape.drawAll();
            break;
            

        case 'p':{
            listDrones(droneNameArr,droneLocArr);
            cout<<"Podaj numer drona: "<<endl;
            cin>>nr;
            cout<<"Podaj kolejno wysokosc, odleglosc, i kat obrotu drona podczas lotu: ";
            cin>>height;
            checkInput(height);
            cin>>distance;
            checkInput(distance);
            cin>>angle;
            checkInput(angle);
            cout<<endl;
            Wektor<2> newLoc=landscape.flyDrone(nr,angle,height,distance);
            droneLocArr.at(nr-1)=newLoc;
            for(uint i; i<IDs.size();i++){
                if(IDs[i]==droneIDArr[nr-1]){
                    place[i]=newLoc;
                }
            }
            break;
        }
        case 'm':
            menu();
            break;
        
        case 'w':
            cout<<"Wspolrzedne srodka drona (x,y): ";
           // cout<<quadcopter.getCoord()<<endl<<endl;
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