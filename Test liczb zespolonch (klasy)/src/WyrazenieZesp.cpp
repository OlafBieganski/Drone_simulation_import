#include "../inc/WyrazenieZesp.hh"

WyrazenieZesp::WyrazenieZesp(): Arg1(0.0), Op(Op_Dodaj), Arg2(0.0) {}

WyrazenieZesp::WyrazenieZesp(LZespolona _Arg1, Operator _Op, LZespolona _Arg2): Arg1(_Arg1), Op(_Op), Arg2(_Arg2) {}

std::ostream & operator << (std::ostream & strm, const WyrazenieZesp & WyrZ){
    strm<<WyrZ.get_Arg1();
    switch(WyrZ.get_Op()){
        
        case Op_Dodaj:
           strm<<'+';
        break;

        case Op_Dziel:
            strm<<'/';
        break;

        case Op_Mnoz:
            strm<<'*';
        break;

        case Op_Odejmij:
            strm<<'-';
        break;
    }
    
    strm<<WyrZ.get_Arg2()<<'='<<std::endl;
    return strm;
}

std::istream & operator >> (std::istream & strm, WyrazenieZesp & WyrZ){
    char op;
    LZespolona L1, L2;
    strm>>L1;
    WyrZ.set_Arg1(L1);
    strm>>op;
    switch(op){
        
        case '+':
           WyrZ.set_Op(Op_Dodaj);
        break;

        case '/':
            WyrZ.set_Op(Op_Dziel);
        break;

        case '*':
            WyrZ.set_Op(Op_Mnoz);
        break;

        case '-':
            WyrZ.set_Op(Op_Odejmij);
        break;

        default: strm.setstate(std::ios::failbit);
    }
    strm>>L2;
    WyrZ.set_Arg2(L2);
    return strm;
}


LZespolona WyrazenieZesp::Oblicz() const{
    LZespolona wynik;

    switch(Op){
        
        case Op_Dodaj:
           wynik=Arg1+Arg2;
        break;

        case Op_Dziel:
            wynik=Arg1/Arg2;
        break;

        case Op_Mnoz:
            wynik=Arg1*Arg2;
        break;

        case Op_Odejmij:
            wynik=Arg1-Arg2;
        break;
    }

    return wynik;
}
