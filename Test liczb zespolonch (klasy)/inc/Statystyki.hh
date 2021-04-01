#ifndef STATYSTYKI_HH
#define STATYSTYKI_HH

class Statystyki
{   private:

    unsigned int poprawne;
    unsigned int bledne;
    unsigned int szansy;

    public:

    unsigned int ileSzans() const;
    void minusSzansa();
    void ustawSzansy(unsigned int ilosc);    
    void dodajPoprawna();
    void dodajBledna();
    void pokazStatystyki();
    Statystyki();
};


#endif