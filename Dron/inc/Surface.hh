#ifndef SURFACE_HH
#define SURFACE_HH

class Surface{
    private:
    double height;
    public:
    Surface(): height(0.0) {}
    void draw() const;
};

#endif