#ifndef SWEKTOR_HH
#define SWEKTOR_HH

#include <iostream>

//klasa wektora

template <typename STyp, int SWymiar>
class SWektor {
  STyp _Wsp[SWymiar];// wprowadzanie wartosci do tablicy 1-wymiiarowej
  //double Skladowa[ROZMIAR];//wektor ma 3 skladowe (elementy, wartości), je zapisujemy w tablicy o 3 skladnikach

public:
  SWektor(){for(STyp &Wsp: _Wsp) Wsp=0;}
/*
  STyp giveValue(int sth) const{
    return _Wsp[sth];
  } //wydaje na potrzeby funkcji wartosci z komorek
  void getValue(STyp sth2, int sth3){
    return _Wsp[sth3]=sth2;
  }//pobiera wartosci z funkcji do tablicy w klasie
*/
  STyp operator[](unsigned int i) const{return _Wsp[i];}//deklaracja przeciazenia operatora [] w const. To nie bedzie zmieniane, stad const, a przeciazenie jest potrzebne, bo bedziemy wyluskiwac z tablicy posczegolne elementy. //?
  STyp &operator[](unsigned int i){return _Wsp[i];}//odwolanie do bezposredniego dzialania na operatorze

//?????????????????????????????????????????????
  double getSkladowa (unsigned int index) const {//przypisywanie wartosci skladowej
    return Skladowa[index];
  }

  void setSkladowa(unsigned int index, double wartosc){
    Skladowa[index]=wartosc;
  }
//???????????????????????????????????????????????

  SWektor<STyp, SWymiar> operator + (SWektor<STyp,SWymiar> & Wektor2);//tutaj jako ze nadal jestesmy w klasie, to przekazuje tylko jeden argument - poprzedni jest juz domyslny, bo nie musimy go przekazywac z klasy w ktorej jestesmy. Więc domyslnie mamy przekazany argument pierwszy, a kolejny wektor przekazuje tutaj. Dodawanie wektorow bedzie potrzebne do zastosowania metody Gaussa przy obliczaniu wyznacznika macierzy. Stad przeciazenie operatora dodawania.
  SWektor<STyp, SWymiar> operator - (SWektor<STyp,SWymiar> &Wektor2);

  SWektor<STyp, Swymiar> operator * (double Skalar);//tutaj mnoze wektor przez skalar

  SWektor<STyp, SWymiar> operator / (double Skalar);

  double operator * (Wektor Wektor2);//tutaj mnozemy wektory przez siebie, czyli robimy iloczyn skalarny
   //mnoze wektor razy wektor
  //Liczba==Skalar

                  //Wektor operator & (Wektor Wektor2);//iloczyn wektorowy

};//KONIEC KLASY WEKTOR!!!

template <typename STyp, int SWymiar>
  SWektor<STyp, SWymiar> SWektor<STyp,SWymiar>::operator + (SWektor<STyp,SWymiar> &Wektor2) const{//definicja, podobnie jak w LZespolonych, tutaj dodajemy wektory
    SWektor<STyp, SWymiar> Wynik;
    for (unsigned int i=0; i<SWymiar; i++)//++i?
    Wynik[i]=(*this)[i]+Wektor2[i];//(*this) miast Skladowa

    return Wynik;
  }//tutaj jako ze nadal jestesmy w klasie, to przekazuje tylko jeden argument - poprzedni jest juz domyslny, bo nie musimy go przekazywac z klasy w ktorej jestesmy. Więc domyslnie mamy przekazany argument pierwszy, a kolejny wektor przekazuje tutaj. Dodawanie wektorow bedzie potrzebne do zastosowania metody Gaussa przy obliczaniu wyznacznika macierzy. Stad przeciazenie operatora dodawania.
  
  template <typename STyp, int SWymiar>
  SWektor<STyp,SWymiar> SWektor<STyp,SWymiar>::operator - (const SWektor<STyp, SWymiar> &Wektor2) const {//tutaj odejmujemy wektory
    SWektor<Styp, SWymiar> Wynik;
    for (unsigned int i=0; i<SWymiar; i++)//++i?
    Wynik[i]=(*this))[i]-Wektor2[i];

    return Wynik;
}//podobnie

template<typename STyp, int SWymiar>
  SWektor<STyp, SWymiar> SWektor<STyp,SWymiar>::operator * (double Skalar) const{//tutaj mnozymy wektor przez liczbe
    SWektor<STyp, SWymiar> Wynik;
    for (unsigned int i=0; i<SWymiar; i++)
    Wynik[i]=(*this))[i]*Skalar;

    return Wynik;
}//tutaj mnoze wektor przez skalar

template<typename STyp, int SWymiar>
  SWektor<STyp,SWeymiar> SWektor<STyp, SWymiar>::operator / (double Skalar) const{//tutaj dzielimy wektor przez liczbe
    SWektor<STyp, SWymiar> Wynik;
    for (unsigned int i=0; i<SWymiar; i++)
    Wynik[i]=(*this))[i]/Skalar;

    return Wynik;
}//podobnie

template<typename STyp, int SWymiar>
  double operator * (SWektor<STyp, SWymiar> Wektor2){//tutaj mnozemy wektory przez siebie, czyli robimy iloczyn skalarny
    double Wynik=0;

    for (unsigned int i=0; i<SWymiar; i++)
    Wynik=Wynik+((*this))[i]*Wektor2[i]);

    return Wynik;
}//mnoze wektor razy wektor
  //Liczba==Skalar

/*template<typename STyp, int SWymiar>
  Wektor operator & (Wektor Wektor2){//tutaj iloczyn wektorowy
    Wektor Wynik;
    Wynik[0]=Skladowa[1]*Wektor2[2]-Wektor2[1]*Skladowa[2];
    Wynik[1]=-(Skladowa[0]*Wektor2[2]-Wektor2[0]*Skladowa[2]);//znak przeciwny
    Wynik[2]=Skladowa[0]*Wektor2[1]-Wektor2[0]*Skladowa[1];

    return Wynik;
}//iloczyn wektorowy
*/
//!!!!!!!!tu tez musze szablon by wyswietlic chyba
template <typename STyp, int SWymiar>
std::istream& operator >> (std::istream &Strm, SWektor<STyp,SWymiar> &Wek){
    for(unsigned int i=0; i<SWymiar; i++){
        Strm>>Wek[i];//wczytywanie wektora
    }
        return Strm;//zwraca co wczytane
}

template <typename STyp, int SWymiar>
std::ostream& operator << (std::ostream &Strm, const SWektor<STyp, SWymiar> &Wek){
for(unsigned int i=0; i<SWymiar; i++)
Strm<<Wek[i]<<"\t";//robi tabulator
return Strm;
}

#endif