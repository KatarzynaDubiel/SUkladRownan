#include "LZespolona.hh"

#include <iostream>
#include <ostream>

LZespolona  LZespolona::operator + (LZespolona  Skl2){
  LZespolona  Wynik;

  Wynik.set_re() = re + Skl2.get_re();
  Wynik.set_im() = im + Skl2.get_im();
  return Wynik;
}

LZespolona  LZespolona::operator - (LZespolona  Skl2){
  LZespolona  Wynik;

  Wynik.set_re() = re - Skl2.get_re();
  Wynik.set_im() = im - Skl2.get_im();
  return Wynik;
}

LZespolona  LZespolona::operator * (LZespolona  Skl2){
  LZespolona  Wynik;

  Wynik.set_re() = re * Skl2.get_re() - im * Skl2.get_im();
  Wynik.set_im() = re * Skl2.get_im() + Skl2.get_re() * im;

  return Wynik;
}


LZespolona  LZespolona::operator / ( double  Skl2){
  LZespolona  Wynik;

  Wynik.set_re() = re/Skl2;
  Wynik.set_im() = im/Skl2;
  return Wynik;
}




double LZespolona::modul2(){
  return re*re+im*im;
}

LZespolona LZespolona::Sprzezenie(){
  LZespolona Wynik;
  Wynik.set_im()=-im;
    Wynik.set_re()=re;
  return Wynik;
}

LZespolona  LZespolona::operator / (LZespolona  Skl2){
  return *this*Skl2.Sprzezenie()/Skl2.modul2();
}

std::ostream & operator << (std::ostream& Strm, LZespolona Skl1){
    Strm << "("<<Skl1.get_re()<<std::showpos<<Skl1.get_im()<<std::noshowpos<<"i)";
    return Strm;
}

std::istream& operator >> (std::istream& Strm, LZespolona &Skl1){

  char znak;
  Strm>>znak;
  if(znak!='('){
    Strm.setstate(std::ios_base::badbit);
    return Strm;
  }
  Strm>>Skl1.set_re();
  if(Strm.bad())
  return Strm;

  Strm>>Skl1.set_im();
  if(Strm.bad())
  return Strm;

  Strm>>znak;
  if(znak!='i'){
      Strm.setstate(std::ios_base::badbit);
      return Strm;
  }

  Strm>>znak;
  if(znak!=')'){
      Strm.setstate(std::ios_base::badbit);
      return Strm;
  }

  return Strm;
}

bool LZespolona::operator==( LZespolona arg2){
  return ( (re == arg2.get_re()) && (im ==arg2.get_im()) );
}