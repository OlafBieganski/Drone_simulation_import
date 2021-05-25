#include "../inc/Prostopadloscian.hh"

using drawNS::Point3D;
using drawNS::APIGnuPlot3D;
using std::vector;
using std::array;


drawNS::Point3D konwertuj(Wektor<3> punkt){
    return drawNS::Point3D(punkt[0],punkt[1],punkt[2]);
}

std::array<std::array<double,4>,3> Prostopadloscian::dlugoscKrawedzi() const{
    array<array<double,4>,3> zbiorKrawedzi;
    array<double,4> dlugoscKrawedzi1;
    array<double,4> dlugoscKrawedzi2;
    array<double,4> dlugoscWysokosci;
    int i;

    for(i=0;i<8;i+=2){
        dlugoscKrawedzi1[i/2]=(punkty[i+1]-punkty[i]).modul();
    }
    for(i=0;i<4;++i){
        dlugoscWysokosci[i]=(punkty[i+4]-punkty[i]).modul();
    }
    
    dlugoscKrawedzi2[0]=(punkty[3]-punkty[0]).modul();    
    dlugoscKrawedzi2[1]=(punkty[2]-punkty[1]).modul();
    dlugoscKrawedzi2[2]=(punkty[7]-punkty[4]).modul();    
    dlugoscKrawedzi2[3]=(punkty[6]-punkty[5]).modul();

    zbiorKrawedzi[0]=dlugoscKrawedzi1;
    zbiorKrawedzi[1]=dlugoscKrawedzi2;
    zbiorKrawedzi[2]=dlugoscWysokosci;
    
    return zbiorKrawedzi;
}


void Prostopadloscian::draw(){
    vector<Point3D> points1, points2;
    vector<vector<Point3D>> pointsCollection;

    for(int i=0;i<4;++i){
        points1.push_back(konwertuj(punkty[i]));
        points2.push_back(konwertuj(punkty[i+4]));
    }

    pointsCollection.push_back(points1);
    pointsCollection.push_back(points2);
    //rysujemy glowny ksztalt
    shapeID=api->draw_polyhedron(pointsCollection, color);
}


Prostopadloscian::Prostopadloscian(std::array<Wektor<3>, 4> podstawa, double wysokosc, std::shared_ptr<drawNS::Draw3DAPI> _api, std::string _color,
Wektor<3> baseMid, MacierzObr<3> baseOrient, CoordinateSys *ptr_to_parent): DrawingInterface(_api, _color), CoordinateSys(baseMid, baseOrient, ptr_to_parent) {

    Wektor<3> boki[4];
    boki[0]=podstawa[1]-podstawa[0];
    boki[1]=podstawa[2]-podstawa[1];
    boki[2]=podstawa[3]-podstawa[2];
    boki[3]=podstawa[0]-podstawa[3];
    double dlugoscBoku[4];

    for(int i=0;i<4;++i) dlugoscBoku[i]=boki[i].modul();

    if( (dlugoscBoku[0]!=dlugoscBoku[2]) || (dlugoscBoku[1]!=dlugoscBoku[3]) || boki[0]*boki[1]!=0 || boki[2]*boki[3]!=0){
        std::cerr<<"To nie jest prostopadloscian."<<std::endl;
        exit(1);
    }
    Wektor<3> wektorNormalny;
    Wektor<3> X={1,0,0}, Y={0,1,0}, Z={0,0,1};
    
    // iloczyn wektorowy w celu obliczenia wektora normalnego
    wektorNormalny=wektorNormalny+(Z*(boki[0][0]*boki[1][1]));
    wektorNormalny=wektorNormalny+(X*(boki[0][1]*boki[1][2]));
    wektorNormalny=wektorNormalny+(Y*(boki[0][2]*boki[1][0]));
    wektorNormalny=wektorNormalny-(X*(boki[0][2]*boki[1][1]));
    wektorNormalny=wektorNormalny-(Y*(boki[0][0]*boki[1][2]));
    wektorNormalny=wektorNormalny-(Z*(boki[0][1]*boki[1][0]));
    
    //obliczamy wersor wektora normalnego
    Wektor<3> wersor=wektorNormalny*(1/wektorNormalny.modul());

    //wektor wysokosci
    Wektor<3> wysokoscWektor=wersor*wysokosc;

    std::array<Wektor<3>,4> gornapodstawa;

    for(int i=0;i<4;++i){
        gornapodstawa[i]=podstawa[i]+wysokoscWektor;
    }

    for(int i=0;i<4;++i){
        punkty[i]=podstawa[i];
        punkty[i+4]=gornapodstawa[i];
    }
}


const Wektor<3> Prostopadloscian::operator [] (unsigned int ind) const{
    if(ind<8) return punkty[ind];
    std::cerr<<"Blad indeksowania obiektu Prostopadloscian."<<std::endl; 
    exit(1);
}

void Prostopadloscian::translacja(Wektor<3> przesuniecie){
    for(int i=0;i<8;++i){
        punkty[i]=punkty[i]+przesuniecie;
    }
}


void Prostopadloscian::rotacja(MacierzObr<3> obrot){
    for(int i=0;i<8;++i){
        punkty[i]=obrot*punkty[i];
    }
}

Prostopadloscian Prostopadloscian::convert_to_parent() const{

    Prostopadloscian converted;
    converted.middle=this->parent->getMiddle();
    converted.orientation=this->parent->getOrient();
    converted.parent=this->parent->getParent();
    converted.shapeID=this->shapeID;
    converted.color=this->color;
    converted.api=this->api;

    for(int i=0;i<8;i++){
        converted.punkty[i]=(this->orientation*this->punkty[i])+this->middle;
    }

    return converted;
}