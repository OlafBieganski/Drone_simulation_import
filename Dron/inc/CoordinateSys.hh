#ifndef COORDINATESYS
#define COORDINATESYS

#include "Wektor.hh"
#include "MacierzObr.hh"

class CoordinateSys{
    protected:
    Wektor<3> middle;
    MacierzObr<3> orientation;
    public:
    CoordinateSys(): middle(), orientation() {}
    CoordinateSys(Wektor<3> baseMid, MacierzObr<3> baseOrient);
    void rotation(MacierzObr<3> newOrient) {orientation = orientation * newOrient;}
    void translation(Wektor<3> shift) {middle = middle + shift;}
};

#endif