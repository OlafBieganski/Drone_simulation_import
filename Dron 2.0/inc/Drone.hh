#ifndef DRONE
#define DRONE

#include "Prostopadloscian.hh"
#include "DrawingInterface.hh"
#include "Hexagon3D.hh"
#include "CoordinateSys.hh"
#include <iostream>
#include "../API/source/Dr3D_gnuplot_api.hh"

using std::array;

/*!
 * \file Drone.hh
 * Plik zawiera klase Dron 
 */

/*!
 * \brief Klasa Dron
 * Klasa dron - zawiera metody odpowieadajace za poruszanie dronem oraz
 * rysowanie i usuwanie drona
 */
class Drone: public CoordinateSys, public DrawingInterface {
    private:
    /*!
     * \brief korpus drona
     * Obiekt klasy prostopadloscian reprezentujacy
     * korpus drona
    */
    Prostopadloscian frame;
    /*!
     * \brief tablica z wirnikami
     * tablica zawierajaca 4 obiekty Hexagon3D
     * reprezentujace wirniki drona
    */
    array<Hexagon3D,4> rotors;
    /*!
     * \brief obroc wirnikami
     * obraca kazdy wirnik drona o 1 stopien
     */
    void moveRotors();
    public:
    /*!
     * \brief rysuj drona
    */
    void draw() override;
    /*!
     * \brief lec w gore
     * \param height - wysokosc
     */
    void flyHoriz(double height);
    /*!
     * \brief lec poziomo
     * \param distance - dystans przelotu
     */
    void flyVert(double distance);
    /*!
     * \brief obroc sie o zadany kat
     * \param angle_deg - kat obrotu w stopniach
     */
    void turn(double angle_deg);
    /*!
     * \brief laduj na powierzchnie
     */
    void land();
    /*!
     * \brief konstruktor drona
     * \param droneMiddle - polozenie srodka drona w przestrzeni
     * \param api - wskaznik shared_ptr do API
     * \param color - kolor drona (domyslnie czarny)
     */
    Drone(Wektor<3> droneMiddle, std::shared_ptr<drawNS::Draw3DAPI> api, std::string color="black");
    /*!
     * \brief usun drona z gnuplota
     */
    void eraseDrone();
    /*!
     * \brief animowany lot drona
     * \param angle_deg - kat obrotu w stopniach
     * \param height - wysokosc przelotu
     * \param distance - odleglosc przelotu
     */
    void animatedFly(double angle_deg, double height, double distance);
    /*!
     * \brief sprawdz wspolrzedne drona
     * \return pozycja drona na plaszczyznie XY
     */
    Wektor<2> getCoord() const;
};


#endif