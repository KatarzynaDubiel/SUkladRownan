#ifndef SUkladRownanLiniowych_HH
#define SUkladRownanLiniowych_HH

#include <iostream>
#include <cmath>
#include "Macierz.hh"
#include "Wektor.hh"

enum Ilosc_rozwiazan {BRAK_ROZWIAZAN,NIESKONCZENIE_WIELE_ROZWIAZAN,JEDNO_ROZWIAZANIE};

template <typename STyp, int SWymiar>
class SUkladRownanLiniowych {
  SMacierz<STyp,SWymiar> Ma_Wspolcznikow;
  SWektor<STyp,SWymiar> Wek_Wyrazow_Wolnych;
  SWektor<STyp,SWymiar> Wek_wynikow;
  SWektor<STyp,SWymiar> Wek_Bledow;
  STyp Dl_Wek_Bledu;
  public:
  SMacierz<STyp,SWymiar> get_Ma_Wspolcznikow()const {return Ma_Wspolcznikow; }
  SWektor<STyp,SWymiar> get_Wek_Wyrazow_Wolnych()const {return Wek_Wyrazow_Wolnych; }
  SWektor<STyp,SWymiar> get_Wek_wynikow()const {return Wek_wynikow; }
  SWektor<STyp,SWymiar> get_Wek_Bledow()const {return Wek_Bledow; }
  STyp get_Dl_Wek_Bledu()const {return Dl_Wek_Bledu; }
  SMacierz<STyp,SWymiar> &set_Ma_Wspolcznikow() {return Ma_Wspolcznikow; }
  SWektor<STyp,SWymiar> &set_Wek_Wyrazow_Wolnych() {return Wek_Wyrazow_Wolnych; }
  Ilosc_rozwiazan oblicz_wynik();
  void Oblicz_Bledy();
};

template <typename STyp, int SWymiar>
std::istream& operator >> (std::istream &Strm, SUkladRownanLiniowych<STyp,SWymiar> &UklRown){
    Strm>>UklRown.set_Ma_Wspolcznikow()>>UklRown.set_Wek_Wyrazow_Wolnych();
    return Strm;
}

template <typename STyp, int SWymiar>
std::ostream& operator << (std::ostream &Strm, const SUkladRownanLiniowych<STyp,SWymiar> &UklRown){
    Strm<<std::endl<<"Macierz A^T:"<<std::endl;
    Strm<<std::endl<<UklRown.get_Ma_Wspolcznikow()<<std::endl;
    Strm<<"Wektor wyrazow wolnych b:"<<std::endl;
    Strm<<UklRown.get_Wek_Wyrazow_Wolnych()<<std::endl<<std::endl;
    return Strm;
}

template <typename STyp, int SWymiar>
Ilosc_rozwiazan SUkladRownanLiniowych<STyp,SWymiar>::oblicz_wynik(){
    SMacierz<STyp,SWymiar> Kopie[SWymiar];
    Ma_Wspolcznikow.Wyznacznik_Gauss();

    for(int i=0; i<SWymiar; i++){
        Kopie[i]=Ma_Wspolcznikow;
        Kopie[i][i]=Wek_Wyrazow_Wolnych;
        Kopie[i].Wyznacznik_Gauss();
        if(   Ma_Wspolcznikow.get_Wyznacznik()==0 &&Kopie[i].get_Wyznacznik()==0 )
            return NIESKONCZENIE_WIELE_ROZWIAZAN;
    }

    if(Ma_Wspolcznikow.get_Wyznacznik()==0)
        return BRAK_ROZWIAZAN;

    for(int i=0; i<SWymiar; i++){
        Wek_wynikow[i]=Kopie[i].get_Wyznacznik()/Ma_Wspolcznikow.get_Wyznacznik();
    }
    return JEDNO_ROZWIAZANIE;
}

template <typename STyp, int SWymiar>
void SUkladRownanLiniowych<STyp,SWymiar>::Oblicz_Bledy(){
    Wek_Bledow=Ma_Wspolcznikow*Wek_wynikow-Wek_Wyrazow_Wolnych;
    Dl_Wek_Bledu=sqrt(Wek_Bledow*Wek_Bledow);
}

#endif
