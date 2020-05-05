#ifndef SMacierz_HH
#define SMacierz_HH

#include "Wektor.hh"
#include <iostream>
#include <algorithm>

template <typename STyp, int SWymiar>
class SMacierz {
    SWektor<STyp,SWymiar> Kolumna[SWymiar];/*sa 3 wiersze, czyli 3 SWektor<STyp,SWymiar>y*/
    STyp Wyznacznik;
public:
    STyp get_Wyznacznik() const {return Wyznacznik;}

    SWektor<STyp,SWymiar> operator[](int i) const;
    SWektor<STyp,SWymiar> &operator[](int i);
    SMacierz<STyp,SWymiar> Odejmowanie(SMacierz<STyp,SWymiar> Odjemna, SMacierz<STyp,SWymiar> Odjemnik);
    SMacierz<STyp,SWymiar> Mnozenie(SMacierz<STyp,SWymiar> Czynnik1, SMacierz<STyp,SWymiar> Czynnik2);
    SMacierz<STyp,SWymiar> Kwadrat();

    SWektor<STyp,SWymiar> operator * (SWektor<STyp,SWymiar> Skladowy){
        SWektor<STyp,SWymiar> wynik;
        for(int i=0; i<SWymiar; i++){
            wynik[i]=0;
            for(int i=0; i<SWymiar; i++){
                for(int j=0; j<SWymiar; j++){
                    wynik[i]=wynik[i]+Kolumna[j][i]*Skladowy[j];
                }
            }
        }
        return wynik;
    }
  void Wyznacznik_Gauss();
};

template <typename STyp, int SWymiar>
SWektor<STyp,SWymiar> SMacierz<STyp,SWymiar>::operator[](int i) const{
    return Kolumna[i];
}

template <typename STyp, int SWymiar>
SWektor<STyp,SWymiar> &SMacierz<STyp,SWymiar>::operator[](int i){
    return Kolumna[i];
}

template <typename STyp, int SWymiar>
std::istream& operator >> (std::istream &Strm, SMacierz<STyp,SWymiar> &Mac){
    for(int i=0; i<SWymiar; i++)
    Strm>>Mac[i];
    return Strm;
}

template <typename STyp, int SWymiar>
std::ostream& operator << (std::ostream &Strm, const SMacierz<STyp,SWymiar> &Mac){
    for(int i=0; i<SWymiar; i++)
    Strm<<Mac[i]<<std::endl;
    return Strm;
}

template <typename STyp, int SWymiar>
SMacierz<STyp,SWymiar> SMacierz<STyp,SWymiar>::Odejmowanie(SMacierz<STyp,SWymiar> Odjemna, SMacierz<STyp,SWymiar> Odjemnik){
    SMacierz<STyp,SWymiar> M4_wynik;
    for(int i=0; i<10; i++){//chyba powinnam zmienic SWymiar, ale na razie niech tak bedzie
        for(int j=0; j<10; j++){
        M4_wynik[i][j]=Odjemna.Kolumna[i][j]-Odjemnik.Kolumna[i][j];
        }
    }
    return  M4_wynik;
}

template <typename STyp, int SWymiar>
SMacierz<STyp,SWymiar> SMacierz<STyp,SWymiar>::Mnozenie(SMacierz<STyp,SWymiar> Czynnik1, SMacierz<STyp,SWymiar> Czynnik2){
    SMacierz<STyp,SWymiar> M7_iloczyn;

    for(int k=0; k<10; k++){
        for(int j=0; j<10; j++){
            for(int i=0; i<10; i++){
                for(int h=0; h<10; h++){
                    M7_iloczyn[j][k]+=Czynnik1.Kolumna[i][h]*Czynnik2.Kolumna[i][h];
                }
            }//pierwszy element
        }//linia
    }

    return  M7_iloczyn;
}
template <typename STyp, int SWymiar>
SMacierz<STyp,SWymiar> SMacierz<STyp,SWymiar>::Kwadrat(){//kazdy element SMacierz<STyp,SWymiar>y podnosi sie do kwadratu
    SMacierz<STyp,SWymiar> Macierz_Spotegowana;
    for(int i=0; i<SWymiar; i++){
        for(int j=0; j<SWymiar; j++){
        Macierz_Spotegowana[i][j]=Kolumna[i][j]*Kolumna[i][j];
        }
    }
    return  Macierz_Spotegowana;
}
template <typename STyp, int SWymiar>
 void SMacierz<STyp,SWymiar>::Wyznacznik_Gauss(){
     SMacierz<STyp,SWymiar> kopia=*this;
     int j;
     Wyznacznik=1;
     for(int i=0; i<SWymiar; i++){
         j=i;
         while(kopia[i][i]==0){
             j++;
             if(j<SWymiar)
             std::swap(kopia[i],kopia[j]);
             else{
                 Wyznacznik=0;
                 return;
             }
         }
         for(int k=i+1; k<SWymiar; k++){
            kopia[k]=kopia[k]-kopia[i]*(kopia[k][i]/kopia[i][i]);
         }
         Wyznacznik=Wyznacznik*kopia[i][i];
     }
 }

#endif