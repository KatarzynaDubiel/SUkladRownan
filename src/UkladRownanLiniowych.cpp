#include "UkladRownanLiniowych.hh"


std::istream& operator >> (std::istream &Strm, UkladRownanLiniowych &UklRown){
    Strm>>UklRown.set_Ma_Wspolcznikow()>>UklRown.set_Wek_Wyrazow_Wolnych();
    return Strm;
    }

std::ostream& operator << (std::ostream &Strm, const UkladRownanLiniowych &UklRown){
    Strm<<std::endl<<"Macierz A^T:"<<std::endl;
    Strm<<std::endl<<UklRown.get_Ma_Wspolcznikow()<<std::endl;
    Strm<<"Wektor wyrazow wolnych b:"<<std::endl;
    Strm<<UklRown.get_Wek_Wyrazow_Wolnych()<<std::endl<<std::endl;
    return Strm;
}

Ilosc_rozwiazan UkladRownanLiniowych::oblicz_wynik(){
    Macierz Kopie[ROZMIAR];
    Ma_Wspolcznikow.Wyznacznik_Gauss();

    for(int i=0; i<ROZMIAR; i++){
        Kopie[i]=Ma_Wspolcznikow;
        Kopie[i][i]=Wek_Wyrazow_Wolnych;
    Kopie[i].Wyznacznik_Gauss();
        if(   Ma_Wspolcznikow.get_Wyznacznik()==0 &&Kopie[i].get_Wyznacznik()==0 )
    return NIESKONCZENIE_WIELE_ROZWIAZAN;
    }

    if(Ma_Wspolcznikow.get_Wyznacznik()==0)
        return BRAK_ROZWIAZAN;

    for(int i=0; i<ROZMIAR; i++){
        Wek_wynikow[i]=Kopie[i].get_Wyznacznik()/Ma_Wspolcznikow.get_Wyznacznik();
    }
    return JEDNO_ROZWIAZANIE;
}

void UkladRownanLiniowych::Oblicz_Bledy(){
    Wek_Bledow=Ma_Wspolcznikow*Wek_wynikow-Wek_Wyrazow_Wolnych;
    Dl_Wek_Bledu=sqrt(Wek_Bledow*Wek_Bledow);
}