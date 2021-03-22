#include "../inc/WyrazenieZesp.hh"
#include <iostream>

void Wyswietl(WyrazenieZesp  WyrZ){
    std::cout<<WyrZ.Arg1;
    switch(WyrZ.Op){
        
        case Op_Dodaj:
           std::cout<<'+';
        break;

        case Op_Dziel:
            std::cout<<'/';
        break;

        case Op_Mnoz:
            std::cout<<'*';
        break;

        case Op_Odejmij:
            std::cout<<'-';
        break;
    }
    
    std::cout<<WyrZ.Arg2<<'='<<std::endl;
}
LZespolona Oblicz(WyrazenieZesp  WyrZ){
    LZespolona wynik;

    switch(WyrZ.Op){
        
        case Op_Dodaj:
           wynik=WyrZ.Arg1+WyrZ.Arg2;
        break;

        case Op_Dziel:
            wynik=WyrZ.Arg1/WyrZ.Arg2;
        break;

        case Op_Mnoz:
            wynik=WyrZ.Arg1*WyrZ.Arg2;
        break;

        case Op_Odejmij:
            wynik=WyrZ.Arg1-WyrZ.Arg2;
        break;
    }

    return wynik;
}
