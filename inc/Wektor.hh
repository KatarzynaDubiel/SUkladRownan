#ifndef SWektor_HH
#define SWektor_HH
#include "LZespolona.hh"
#include <iostream>

template <typename STyp, int SWymiar>
class SWektor {
  STyp Skladowa[SWymiar];//SWektor<STyp,SWymiar> ma 3 skladowe (elementy, wartości), je zapisujemy w tablicy o 3 skladnikach

public:
    STyp operator[](int i) const;//deklaracja przeciazenia operatora [] w const. To nie bedzie zmieniane, stad const, a przeciazenie jest potrzebne, bo bedziemy wyluskiwac z tablicy posczegolne elementy.
    STyp &operator[](int i);//odwolanie do bezposredniego dzialania na operatorze

    STyp getSkladowa (unsigned int index) const {//pobieranie wartosci skladowej
    return Skladowa[index];
  }

  void setSkladowa(unsigned int index, STyp wartosc){
    Skladowa[index]=wartosc;
  }

    SWektor<STyp,SWymiar> operator + (SWektor<STyp,SWymiar> Wektor2);//tutaj jako ze nadal jestesmy w klasie, to przekazuje tylko jeden argument - poprzedni jest juz domyslny, bo nie musimy go przekazywac z klasy w ktorej jestesmy. Więc domyslnie mamy przekazany argument pierwszy, a kolejny SWektor<STyp,SWymiar> przekazuje tutaj. Dodawanie SWektor<STyp,SWymiar>ow bedzie potrzebne do zastosowania metody Gaussa przy obliczaniu wyznacznika macierzy. Stad przeciazenie operatora dodawania.
    SWektor<STyp,SWymiar> operator - (SWektor<STyp,SWymiar> Wektor2);//podobnie
    SWektor<STyp,SWymiar> operator * (STyp Skalar);//tutaj mnoze SWektor<STyp,SWymiar> przez skalar
    SWektor<STyp,SWymiar> operator / (STyp Skalar);//podobnie
    STyp operator * (SWektor<STyp,SWymiar> Wektor2);//mnoze SWektor<STyp,SWymiar> razy SWektor<STyp,SWymiar>
    //Liczba==Skalar

};

template <typename STyp, int SWymiar>
STyp SWektor<STyp,SWymiar>::operator[](int i) const{
    return Skladowa[i];
}//zwraca skladnik wektora, czyli tablicy

template <typename STyp, int SWymiar>
STyp &SWektor<STyp,SWymiar>::operator[](int i){
    return Skladowa[i];
}

template <typename STyp, int SWymiar>
std::istream& operator >> (std::istream &Strm, SWektor<STyp,SWymiar> &Wek){
    for(int i=0; i<SWymiar; i++){
        Strm>>Wek[i];//wczytywanie wektora
    }
        return Strm;//zwraca co wczytane
}

template <typename STyp, int SWymiar>
std::ostream& operator << (std::ostream &Strm, const SWektor<STyp,SWymiar> &Wek){
    for(int i=0; i<SWymiar; i++)
    Strm<<Wek[i]<<"\t";//robi tabulator
    return Strm;
}

template <typename STyp, int SWymiar>
SWektor<STyp,SWymiar> SWektor<STyp,SWymiar>::operator + (SWektor<STyp,SWymiar> Wektor2){
    SWektor<STyp,SWymiar> Wynik;
    for (int i=0; i<SWymiar; i++)
    Wynik[i]=Skladowa[i]+Wektor2[i];
    return Wynik;
}

template <typename STyp, int SWymiar>
SWektor<STyp,SWymiar> SWektor<STyp,SWymiar>::operator - (SWektor<STyp,SWymiar> Wektor2){//tutaj odejmujemy wektory
    SWektor<STyp,SWymiar> Wynik;
    for (int i=0; i<SWymiar; i++)
    Wynik[i]=Skladowa[i]-Wektor2[i];
    return Wynik;
}

template <typename STyp, int SWymiar>
SWektor<STyp,SWymiar> SWektor<STyp,SWymiar>::operator * (STyp Skalar){//tutaj mnozymy SWektor<STyp,SWymiar> przez liczbe
    SWektor<STyp,SWymiar> Wynik;
    for (int i=0; i<SWymiar; i++)
    Wynik[i]=Skladowa[i]*Skalar;
    return Wynik;
}

template <typename STyp, int SWymiar>
SWektor<STyp,SWymiar> SWektor<STyp,SWymiar>::operator / (STyp Skalar){//tutaj dzielimy SWektor<STyp,SWymiar> przez liczbe
    SWektor<STyp,SWymiar> Wynik;
    for (int i=0; i<SWymiar; i++)
    Wynik[i]=Skladowa[i]/Skalar;
    return Wynik;
}
template <typename STyp, int SWymiar>
STyp SWektor<STyp,SWymiar>::operator * (SWektor<STyp,SWymiar> Wektor2){//tutaj mnozemy wektory przez siebie, czyli robimy iloczyn wektorowy
    STyp Wynik=0;

    for (int i=0; i<SWymiar; i++)
    Wynik=Wynik+(Skladowa[i]*Wektor2[i]);

    return Wynik;
}

#endif