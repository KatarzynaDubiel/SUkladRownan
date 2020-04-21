#ifndef UKLADROWNANLINIOWYCH_HH
#define UKLADROWNANLINIOWYCH_HH

#include <iostream>
#include <cmath>
#include "Macierz.hh"
#include "Wektor.hh"

enum Ilosc_rozwiazan {BRAK_ROZWIAZAN,NIESKONCZENIE_WIELE_ROZWIAZAN,JEDNO_ROZWIAZANIE};
/*
 *  Tutaj trzeba opisac klase. Jakie pojecie modeluje ta klasa
 *  i jakie ma glowne cechy.
 */
class UkladRownanLiniowych {
  Macierz Ma_Wspolcznikow;
  Wektor Wek_Wyrazow_Wolnych;
  Wektor Wek_wynikow;
  Wektor Wek_Bledow;
  double Dl_Wek_Bledu;
  public:
  Macierz get_Ma_Wspolcznikow()const {return Ma_Wspolcznikow; }
  Wektor get_Wek_Wyrazow_Wolnych()const {return Wek_Wyrazow_Wolnych; }
  Wektor get_Wek_wynikow()const {return Wek_wynikow; }
  Wektor get_Wek_Bledow()const {return Wek_Bledow; }
  double get_Dl_Wek_Bledu()const {return Dl_Wek_Bledu; }
  Macierz &set_Ma_Wspolcznikow() {return Ma_Wspolcznikow; }
  Wektor &set_Wek_Wyrazow_Wolnych() {return Wek_Wyrazow_Wolnych; }
  Ilosc_rozwiazan oblicz_wynik();
  void Oblicz_Bledy();
};
/*
 * To przeciazenie trzeba opisac. Co ono robi. Jaki format
 * danych akceptuje. Jakie jest znaczenie parametrow itd.
 * Szczegoly dotyczace zalecen realizacji opisow mozna
 * znalezc w pliku:
 *    ~bk/edu/kpo/zalecenia.txt
 */
std::istream& operator >> (std::istream &Strm, UkladRownanLiniowych &UklRown);
/*
 * To przeciazenie trzeba opisac. Co ono robi. Jaki format
 * danych akceptuje. Jakie jest znaczenie parametrow itd.
 * Szczegoly dotyczace zalecen realizacji opisow mozna
 * znalezc w pliku:
 *    ~bk/edu/kpo/zalecenia.txt
 */
std::ostream& operator << (std::ostream &Strm,const UkladRownanLiniowych &UklRown);

#endif
