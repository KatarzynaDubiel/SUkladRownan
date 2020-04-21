#ifndef WEKTOR_HH
#define WEKTOR_HH

#include "rozmiar.h"
#include <iostream>
/*
 *  Tutaj trzeba opisac klase. Jakie pojecie modeluje ta klasa
 *  i jakie ma glowne cechy.
 */
class Wektor {
  double Skladowa[ROZMIAR];//wektor ma 3 skladowe (elementy, wartości), je zapisujemy w tablicy o 3 skladnikach

public:
double operator[](int i) const;//deklaracja przeciazenia operatora [] w const. To nie bedzie zmieniane, stad const, a przeciazenie jest potrzebne, bo bedziemy wyluskiwac z tablicy posczegolne elementy. //?
double &operator[](int i);//odwolanie do bezposredniego dzialania na operatorze

  double getSkladowa (unsigned int index) const {//przypisywanie wartosci skladowej
    return Skladowa[index];
  }

  void setSkladowa(unsigned int index, double wartosc){
    Skladowa[index]=wartosc;
  }

Wektor operator + (Wektor Wektor2);//tutaj jako ze nadal jestesmy w klasie, to przekazuje tylko jeden argument - poprzedni jest juz domyslny, bo nie musimy go przekazywac z klasy w ktorej jestesmy. Więc domyslnie mamy przekazany argument pierwszy, a kolejny wektor przekazuje tutaj. Dodawanie wektorow bedzie potrzebne do zastosowania metody Gaussa przy obliczaniu wyznacznika macierzy. Stad przeciazenie operatora dodawania.
Wektor operator - (Wektor Wektor2);//podobnie
Wektor operator * (double Skalar);//tutaj mnoze wektor przez skalar
Wektor operator / (double Skalar);//podobnie
double operator * (Wektor Wektor2);//mnoze wektor razy wektor
//Liczba==Skalar

Wektor operator & (Wektor Wektor2);//iloczyn wektorowy

};

/*
 * To przeciazenie trzeba opisac. Co ono robi. Jaki format
 * danych akceptuje. Jakie jest znaczenie parametrow itd.
 * Szczegoly dotyczace zalecen realizacji opisow mozna
 * znalezc w pliku:
 *    ~bk/edu/kpo/zalecenia.txt
 */
std::istream& operator >> (std::istream &Strm, Wektor &Wek);

/*
 * To przeciazenie trzeba opisac. Co ono robi. Jaki format
 * danych akceptuje. Jakie jest znaczenie parametrow itd.
 * Szczegoly dotyczace zalecen realizacji opisow mozna
 * znalezc w pliku:
 *    ~bk/edu/kpo/zalecenia.txt
 */
std::ostream& operator << (std::ostream &Strm, const Wektor &Wek);

#endif