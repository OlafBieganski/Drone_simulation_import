#include "../inc/Wektor2D.hh"
#include "../inc/Macierz2x2.hh"
#include "../inc/Prostokat.hh"
#include "../API2D/source/Dr2D_gnuplot_api.hh"

using drawNS::APIGnuPlot2D;

void wait4key() {
  do {
    std::cout << "\n Press a key to continue..." << std::endl;
  } while(std::cin.get() != '\n');
}

int main(){
    //Wektor2D vector1(4,1), vector3(4,5), vector4(6,3);
    //Wektor2D vector2(2.0, 3.0);
    Wektor2D vector1(1,1), vector3(3,4), vector4(3,1);
    Wektor2D vector2(1,4);
    
    Prostokat rectangle(vector1,vector2,vector3,vector4);
    Prostokat rotated;
    std::shared_ptr<drawNS::Draw2DAPI> rysownik(new APIGnuPlot2D(-10,10,-10,10,0));
    rectangle.rysuj(rysownik);
    
    wait4key();
    rotated=rectangle.rotacja(3.14);
    rotated.rysuj(rysownik);

    std::cout<<vector1<<std::endl<<vector3<<std::endl;

    vector1[0]=vector2[1]; vector1[1]=1.0;
    double wynik=vector1*vector2;

    std::cout<<vector1<<std::endl<<vector2<<std::endl;

    std::cout<<wynik<<std::endl;

    Macierz2x2 matrix1, matrix2;
    Macierz2x2 matrix3(30.0);
    matrix2.setAngle(10.0);
    matrix1=matrix2*matrix3;
    std::cout<<matrix1<<std::endl<<matrix2<<std::endl<<matrix3<<std::endl;
    vector1=matrix3*vector2;
    std::cout<<vector1<<std::endl;

    return 0;
}
