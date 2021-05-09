#ifndef COORDINATESYS
#define COORDINATESYS

#include "Wektor.hh"
#include "MacierzObr.hh"

class CoordinateSys{
    protected:
    CoordinateSys *parent;
    Wektor<3> middle;
    MacierzObr<3> orientation;
    public:
    CoordinateSys(): middle(), orientation() {parent=nullptr;}
    CoordinateSys(Wektor<3> baseMid, MacierzObr<3> baseOrient, CoordinateSys *ptr_to_parent) {middle=baseMid; orientation=baseOrient; parent=ptr_to_parent;}
    void rotateSys(MacierzObr<3> newOrient) {orientation = orientation * newOrient;}
    void translateSys(Wektor<3> shift) {middle = middle + shift;}
    CoordinateSys* getParent() const {return parent;}
    Wektor<3> getMiddle() const {return middle;}
    MacierzObr<3> getOrient() const {return orientation;}
};

#endif