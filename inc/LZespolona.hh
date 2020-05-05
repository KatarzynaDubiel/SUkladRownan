#ifndef LZESPOLONA_HH
#define LZESPOLONA_HH

#include <iostream>
#include <ostream>

class  LZespolona {
  double   re;
  double   im;
  public:
  LZespolona(double re=0, double im=0){
    this->re=re;
    this->im=im;
  }
  double get_re() const{return re;}
  double get_im() const{return im;}
  double &set_re() {return re;}
  double &set_im() {return im;}
  LZespolona  operator + ( LZespolona  Skl2);
  LZespolona  operator - ( LZespolona  Skl2);
  LZespolona  operator * ( LZespolona  Skl2);
  LZespolona  operator / ( LZespolona  Skl2);
  LZespolona operator / ( double  skalar);

  bool operator==( LZespolona arg2);
  double modul2();
  LZespolona Sprzezenie();
};

std::ostream & operator << (std::ostream& Strm, LZespolona Skl1);
std::istream & operator >> (std::istream& Strm, LZespolona &Skl1);

#endif