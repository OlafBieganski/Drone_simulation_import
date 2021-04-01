#ifndef LZESPOLONA_HH
#define LZESPOLONA_HH
#include <iostream>


class LZespolona {
  private:
  double   re;
  double   im;
  public:
  LZespolona  operator + (const LZespolona & Skl2) const;
  LZespolona  operator - (const LZespolona & Skl2) const;
  LZespolona  operator * (const LZespolona & Skl2) const;
  LZespolona  operator / (const LZespolona & Skl2) const;
  LZespolona  operator / (const double & Skl2) const;
  double  modulKwadrat() const;
  LZespolona sprzezenie() const;
  bool  operator != (const LZespolona &  Skl2) const;
  bool  operator == (const LZespolona &  Skl2) const;
  LZespolona(double _re, double _im);
  LZespolona();
  explicit LZespolona(double _re);
  double get_re() const {return re;};
  double get_im() const {return im;};
  void set_re(double _re){re=_re;}
  void set_im(double _im){im=_im;}
};

std::ostream & operator << (std::ostream & strm, const LZespolona & L);
std::istream & operator >>(std::istream &strm, LZespolona & L);



#endif
