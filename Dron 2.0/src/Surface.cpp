#include "../inc/Surface.hh"
#include <vector>

#define WIDTH 3  // ilosc punktow tworzacych bok siatki
#define SIDE_LENGHT 20 // dlugosc boku jednego kwadratu

using std::vector;
using drawNS::Point3D;

void Surface::draw(){
    vector<vector<Point3D>> pointsCollection;
    vector<Point3D> points;
    
    int x=0; //zmiana punktu
    for(int i=0;i<WIDTH;i++){
        points.push_back(Point3D((double) x, 0, height));
        x+=SIDE_LENGHT;
    }
    pointsCollection.push_back(points);

    int y=SIDE_LENGHT;
    for(int i=1;i<WIDTH;i++){
        x=0;
        for(int j=0;j<WIDTH;j++){
            points.at(j)=Point3D((double) x, (double) y, height);
            x+=SIDE_LENGHT;
        }
        y+=SIDE_LENGHT; // przesuwamy wspolrzedne y
        pointsCollection.push_back(points);
    }

    shapeID=api->draw_surface(pointsCollection, color);
}