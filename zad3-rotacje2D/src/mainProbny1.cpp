#include "../inc/Wektor2D.hh"
#include "../inc/Macierz2x2.hh"

int main(){
    Wektor2D vector1, vector3;
    Wektor2D vector2(2.0, 3.0);

    std::cout<<vector1<<std::endl<<vector2<<std::endl;

    vector1[0]=vector2[1]; vector1[1]=1.0;
    double wynik=vector1*vector2;

    std::cout<<vector1<<std::endl<<vector2<<std::endl;

    std::cout<<wynik<<std::endl;

    Macierz2x2 matrix1, matrix2;
    Macierz2x2 matrix3(30.0);
    matrix2.setAngle(10.0);
    matrix1=matrix2*matrix3;
    std::cout<<matrix1<<' '<<matrix2<<' '<<matrix3<<std::endl;
    vector1=matrix3*vector2;
    std::cout<<vector1<<std::endl;

    return 0;
}
