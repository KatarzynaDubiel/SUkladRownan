#ifndef MACIERZ_HH
#define MACIERZ_HH

#include "rozmiar.h"
#include "Wektor.hh"
#include <iostream>
#include <algorithm>

/*
 *  Tutaj trzeba opisac klase. Jakie pojecie modeluje ta klasa
 *  i jakie ma glowne cechy.
 */
class Macierz {
  Wektor Kolumna[ROZMIAR];/*sa 3 wiersze, czyli 3 wektory*/
  double Wyznacznik;
public:
double get_Wyznacznik() const {return Wyznacznik;}
  Wektor operator[](int i) const;
  Wektor &operator[](int i);

Macierz Kwadrat();
Wektor operator * (Wektor Skladowy){
  Wektor wynik;
  for(int i=0; i<ROZMIAR; i++){
    wynik[i]=0;
    for(int i=0; i<ROZMIAR; i++){
      for(int j=0; j<ROZMIAR; j++){
        wynik[i]=wynik[i]+Kolumna[j][i]*Skladowy[j];
      }
    }
  }
return wynik;
}
  void Wyznacznik_Gauss();
  //Wektor Kolumna[ROZMIAR];
};
/*
 * To przeciazenie trzeba opisac. Co ono robi. Jaki format
 * danych akceptuje. Jakie jest znaczenie parametrow itd.
 * Szczegoly dotyczace zalecen realizacji opisow mozna
 * znalezc w pliku:
 *    ~bk/edu/kpo/zalecenia.txt
 */
std::istream& operator >> (std::istream &Strm, Macierz &Mac);

/*
 * To przeciazenie trzeba opisac. Co ono robi. Jaki format
 * danych akceptuje. Jakie jest znaczenie parametrow itd.
 * Szczegoly dotyczace zalecen realizacji opisow mozna
 * znalezc w pliku:
 *    ~bk/edu/kpo/zalecenia.txt
 */
std::ostream& operator << (std::ostream &Strm, const Macierz &Mac);

#endif

//KLASY I METODY WARUNKI PRE I POST
