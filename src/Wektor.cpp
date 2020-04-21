#include "Wektor.hh"

double Wektor::operator[](int i) const{
    return Skladowa[i];
}//zwraca skladnik wektora, czyli tablicy

double &Wektor::operator[](int i){
    return Skladowa[i];
}

std::istream& operator >> (std::istream &Strm, Wektor &Wek){
    for(int i=0; i<ROZMIAR; i++){
        Strm>>Wek[i];//wczytywanie wektora
    }
        return Strm;//zwraca co wczytane
}

std::ostream& operator << (std::ostream &Strm, const Wektor &Wek){
for(int i=0; i<ROZMIAR; i++)
Strm<<Wek[i]<<"\t";//robi tabulator
return Strm;
}

Wektor Wektor::operator + (Wektor Wektor2){//definicja, podobnie jak w LZespolonych, tutaj dodajemy wektory
    Wektor Wynik;
    for (int i=0; i<ROZMIAR; i++)
    Wynik[i]=Skladowa[i]+Wektor2[i];

    return Wynik;
}

Wektor Wektor::operator - (Wektor Wektor2){//tutaj odejmujemy wektory
    Wektor Wynik;
    for (int i=0; i<ROZMIAR; i++)
    Wynik[i]=Skladowa[i]-Wektor2[i];

    return Wynik;
}

Wektor Wektor::operator * (double Skalar){//tutaj mnozymy wektor przez liczbe
    Wektor Wynik;
    for (int i=0; i<ROZMIAR; i++)
    Wynik[i]=Skladowa[i]*Skalar;

    return Wynik;
}

Wektor Wektor::operator / (double Skalar){//tutaj dzielimy wektor przez liczbe
    Wektor Wynik;
    for (int i=0; i<ROZMIAR; i++)
    Wynik[i]=Skladowa[i]/Skalar;

    return Wynik;
}

double Wektor::operator * (Wektor Wektor2){//tutaj mnozemy wektory przez siebie, czyli robimy iloczyn skalarny
    double Wynik=0;

    for (int i=0; i<ROZMIAR; i++)
    Wynik=Wynik+(Skladowa[i]*Wektor2[i]);

    return Wynik;
}

Wektor Wektor::operator & (Wektor Wektor2){//tutaj iloczyn wektorowy
    Wektor Wynik;
    Wynik[0]=Skladowa[1]*Wektor2[2]-Wektor2[1]*Skladowa[2];
    Wynik[1]=-(Skladowa[0]*Wektor2[2]-Wektor2[0]*Skladowa[2]);//znak przeciwny
    Wynik[2]=Skladowa[0]*Wektor2[1]-Wektor2[0]*Skladowa[1];

    return Wynik;
}