#include "../inc/Hill.hh"

using std::vector;
using drawNS::Point3D;
using std::cout;
using std::endl;

Hill::Hill(Wektor<2> location, uint _vertNr, std::shared_ptr<drawNS::Draw3DAPI> _api, std::string _color): DrawingInterface(_api,_color), CoordinateSys() {
    
    Wektor<3> location2={location[0],location[1],0};
    vertNr=_vertNr;

    Wektor<3> v={double(rand()%10+1),double(rand()%10+1),0};
    v=v*(1/v.modul());

    uint angleSum=359;
    for(uint i=0;i<vertNr;i++){
        
        double randAngle=(double(rand()%(angleSum/(vertNr-i))+1)*M_PI)/180;
        angleSum-=(randAngle*180)/M_PI;
        MacierzObr<3> m(randAngle,"OZ");
        v=m*v;
        verticies.push_back(location2+(v*(rand()%10+1)));
    }

    Wektor<3> randHight={0,0,double(rand()%20+1)};
    verticies.push_back(location2+randHight);
}

drawNS::Point3D convert(Wektor<3> point){
    return drawNS::Point3D(point[0],point[1],point[2]);
}

void Hill::draw(){

    vector<Point3D> points1, points2;
    vector<vector<Point3D>> pointsCollection;

    for(uint i=0;i<vertNr;++i){
        points1.push_back(convert(verticies[i]));
    }

    for(uint i=0;i<vertNr;i++) points2.push_back(convert(verticies[vertNr]));

    pointsCollection.push_back(points1);
    pointsCollection.push_back(points2);
    //rysujemy glowny ksztalt
    shapeID=api->draw_polyhedron(pointsCollection, color);
}
