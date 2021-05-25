#include "../inc/Hill.hh"

using std::vector;
using drawNS::Point3D;

Hill::Hill(Wektor<2> location, uint _vertNr, std::shared_ptr<drawNS::Draw3DAPI> _api, std::string _color): DrawingInterface(_api,_color), CoordinateSys() {
    
    Wektor<3> location2={location[0],location[1],0};
    vertNr=_vertNr;

    for(int i=0;i<vertNr;i++){
        Wektor<3> v={double(rand()%10+1),double(rand()%10+1),0};
        double randAngle=(double(rand()%90+1)*M_PI)/180;
        MacierzObr<3> m(randAngle,"OZ");
        v=m*v;
        verticies.push_back(location2+v);
    }

    Wektor<3> randHight={0,0,double(rand()%20+1)};
    verticies.push_back(verticies[vertNr+1]+randHight);
}

void Hill::draw(){

    vector<Point3D> points1, points2;
    vector<vector<Point3D>> pointsCollection;

    for(int i=0;i<vertNr;++i){
        points1.push_back(convert(verticies[i]));
    }

    points2.push_back(convert(verticies[vertNr+1]));

    pointsCollection.push_back(points1);
    pointsCollection.push_back(points2);
    //rysujemy glowny ksztalt
    shapeID=api->draw_polyhedron(pointsCollection, color);
}

drawNS::Point3D convert(Wektor<3> point){
    return drawNS::Point3D(point[0],point[1],point[2]);
}