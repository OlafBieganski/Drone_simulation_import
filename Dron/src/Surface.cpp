#include "../inc/Surface.hh"
#include <vector>

using std::vector;
using drawNS::Point3D;

void Surface::draw(std::shared_ptr<drawNS::Draw3DAPI> api, std::string color) const{
    vector<vector<Point3D>> pointsCollection;
    vector<Point3D> points;

    for(int i=0;i<100;i++){
        points.push_back(Point3D((double) i, 0, height));
    }
    pointsCollection.push_back(points);

    for(int i=1;i<100;i++){
        for(int j=0;j<100;j++){
            points.at(j)=Point3D((double) j, (double) i, height);
        }
        pointsCollection.push_back(points);
    }

    api->draw_surface(pointsCollection, color);
}