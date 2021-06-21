#include "../inc/Hexagon3D.hh"
#include <numeric>
#include <vector>

using std::vector;


drawNS::Point3D convertPoint(Wektor<3> punkt){
    return drawNS::Point3D(punkt[0],punkt[1],punkt[2]);
}


Hexagon3D::Hexagon3D(Wektor<3> middle, double diagonal, double height, std::shared_ptr<drawNS::Draw3DAPI> _api, std::string _color): DrawingInterface(_api,_color),
 CoordinateSys() 
{

    MacierzObr<3> turn((M_PI/3.0), "OZ");
    Wektor<3> v1={0,0,1}, v2={1,0,0};
    
    v1=v1*(height/2);
    v2=v2*(diagonal/2);

    for(int i=0;i<6;i++){
        verticies[i]=middle+v1+v2;
        verticies[i+6]=middle-v1+v2;
        v2=turn*v2;
    }
}


Hexagon3D::Hexagon3D(): CoordinateSys() {

    Wektor<3> point1={1,1,0}, point2={1,1,1};
    MacierzObr<3> turn((M_PI/3.0), "OZ");

    for(int i=0;i<6;i++){
        verticies[i]=point1;
        verticies[i+6]=point2;
        point1=turn*point1;
        point2=turn*point2;
    }
}

Hexagon3D::Hexagon3D(std::array<Wektor<3>,6> base, double height, std::shared_ptr<drawNS::Draw3DAPI> _api, std::string _color, Wektor<3> baseMid, MacierzObr<3> baseOrient, CoordinateSys *ptr_to_parent)
: DrawingInterface(_api,_color), CoordinateSys(baseMid,baseOrient,ptr_to_parent) {

    int i;
    std::array<double,3> diagonals;

    for(i=0;i<3;i++){
        diagonals[i]=(base[i]-base[i+3]).modul();
    }

    std::array<Wektor<3>,6> sides;
    std::array<double,6> sideLenght;

    for(i=0;i<5;i++){
        sides[i]=base[i]-base[i+1];
        sideLenght[i]=sides[i].modul();
    }
    sides[5]=base[5]-base[0];
    sideLenght[i]=sides[i].modul();

    double average_of_sides=std::accumulate(sideLenght.begin(),sideLenght.end(),0)/6;
    double average_of_diagonals=(diagonals[0]+diagonals[1]+diagonals[3])/3;

    if(average_of_diagonals!=diagonals[0] || average_of_sides!=sideLenght[0]){
        std::cerr<<"To nie jest Graniastoslup foremny o podstawie szesciokata."<<std::endl;
        exit(1);
    }

    Wektor<3> normal;
    Wektor<3> X={1,0,0}, Y={0,1,0}, Z={0,0,1};
    
    // iloczyn wektorowy w celu obliczenia wektora normalnego
    normal=normal+(Z*(sides[0][0]*sides[1][1]));
    normal=normal+(X*(sides[0][1]*sides[1][2]));
    normal=normal+(Y*(sides[0][2]*sides[1][0]));
    normal=normal-(X*(sides[0][2]*sides[1][1]));
    normal=normal-(Y*(sides[0][0]*sides[1][2]));
    normal=normal-(Z*(sides[0][1]*sides[1][0]));
    
    //obliczamy wersor wektora normalnego
    Wektor<3> versor=normal*(1/normal.modul());

    //wektor wysokosci
    Wektor<3> heightVector=versor*height;

    std::array<Wektor<3>, 6> upperBase;

    for(i=0;i<6;i++){
        upperBase[i]=base[i]+heightVector;
        verticies[i]=base[i];
        verticies[i+6]=upperBase[i];
    }
}


const Wektor<3> Hexagon3D::operator [] (unsigned int ind) const{
    if(ind<11)
    return verticies[ind];
    std::cerr<<"Blad indeksowania Hexagon3D"<<std::endl;
    exit(1);
}


void Hexagon3D::draw(){

    vector<vector<drawNS::Point3D>> drawingSet;
    vector<drawNS::Point3D> set1, set2;
    int i;

    for(i=0;i<6;i++){
        set1.push_back(convertPoint(verticies[i]));
        set2.push_back(convertPoint(verticies[i+6]));
    }

    drawingSet.push_back(set1);
    drawingSet.push_back(set2);

    shapeID=api->draw_polyhedron(drawingSet, color);
}


void Hexagon3D::translation(Wektor<3> shift){
    for(int i=0;i<12;i++){
        verticies[i]=verticies[i]+shift;
    }
}


void Hexagon3D::rotation(MacierzObr<3> rotationMatrix){
    for(int i=0;i<12;i++){
        verticies[i]=rotationMatrix*verticies[i];
    }
}

Hexagon3D Hexagon3D::convert_to_parent() const{

    Hexagon3D converted;
    converted.middle=this->parent->getMiddle();
    converted.orientation=this->parent->getOrient();
    converted.parent=this->parent->getParent();
    converted.shapeID=this->shapeID;
    converted.color=this->color;
    converted.api=this->api;

    for(int i=0;i<12;i++){
        converted.verticies[i]=(this->orientation*this->verticies[i])+this->middle;
    }

    return converted;
}

Hexagon3D Hexagon3D::convert_to_granpa() const{

    Hexagon3D converted;
    converted=this->convert_to_parent();
    converted=converted.convert_to_parent();
    return converted;
}