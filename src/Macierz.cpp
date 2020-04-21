#include "Macierz.hh"
#include "Wektor.hh"

Wektor Macierz::operator[](int i) const{
    return Kolumna[i];
}
Wektor &Macierz::operator[](int i){
    return Kolumna[i];
}

std::istream& operator >> (std::istream &Strm, Macierz &Mac){
    for(int i=0; i<ROZMIAR; i++)
    Strm>>Mac[i];

    return Strm;
}

std::ostream& operator << (std::ostream &Strm, const Macierz &Mac){
    for(int i=0; i<ROZMIAR; i++)
    Strm<<Mac[i]<<std::endl;
    return Strm;
}

Macierz Macierz::Kwadrat(){//kazdy element macierzy podnosi sie do kwadratu
    Macierz Macierz_Spotegowana;
    for(int i=0; i<ROZMIAR; i++){
        for(int j=0; j<ROZMIAR; j++){
        Macierz_Spotegowana[i][j]=Kolumna[i][j]*Kolumna[i][j];
        }
    }
    return  Macierz_Spotegowana;
}

 void Macierz::Wyznacznik_Gauss(){
     Macierz kopia=*this;
     int j;
     Wyznacznik=1;
     for(int i=0; i<ROZMIAR; i++){
         j=i;
         while(kopia[i][i]==0){
             j++;
             if(j<ROZMIAR)
             std::swap(kopia[i],kopia[j]);
             else{
                 Wyznacznik=0;
                 return;
             }
         }
         for(int k=i+1; k<ROZMIAR; k++){
            kopia[k]=kopia[k]-kopia[i]*(kopia[k][i]/kopia[i][i]);
         }
         Wyznacznik=Wyznacznik*kopia[i][i];
     }
 }