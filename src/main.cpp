#include <iostream>
#include "Wektor.hh"
#include "Macierz.hh"
#include "UkladRownanLiniowych.hh"
#include "rozmiar.h"

using namespace std;

int main(int argc, char **argv){

char  znak;
cin>>znak;
  if(znak=='r'){
    SUkladRownanLiniowych<double,6>   UklRown;

    cout << endl << " Start programu " <<  endl  <<  endl;
    cin>>UklRown;
    cout<<UklRown;

    switch (UklRown.oblicz_wynik()){

    case JEDNO_ROZWIAZANIE:
      cout<<"Rozwiazanie x = (x1, x2, x3, x4, x5, x6):"<<endl<<endl;
      cout<<UklRown.get_Wek_wynikow()<<endl<<endl;
      cout<<"Wektor bledu Ax-b:"<<endl<<endl;
      cout<<UklRown.get_Wek_Bledow()<<endl<<endl;
      break;

    case NIESKONCZENIE_WIELE_ROZWIAZAN:
      cout<<"NIESKONCZENIE_WIELE_ROZWIAZAN"<<endl;
      break;

    case BRAK_ROZWIAZAN:
      cout<<"Brak rozwiazan"<<endl;
      break;
    }
  }
  else if(znak=='z'){
  SUkladRownanLiniowych<LZespolona,6>   UklRown;

  cout << endl << " Start programu " <<  endl  <<  endl;
  cin>>UklRown;
  cout<<UklRown;

  switch (UklRown.oblicz_wynik()){

    case JEDNO_ROZWIAZANIE:
      cout<<"Rozwiazanie x = (x1, x2, x3, x4, x5, x6):"<<endl<<endl;
      cout<<UklRown.get_Wek_wynikow()<<endl<<endl;
      cout<<"Wektor bledu Ax-b:"<<endl<<endl;
      cout<<UklRown.get_Wek_Bledow()<<endl<<endl;
      break;

    case NIESKONCZENIE_WIELE_ROZWIAZAN:
      cout<<"NIESKONCZENIE_WIELE_ROZWIAZAN"<<endl;
      break;

    case BRAK_ROZWIAZAN:
      cout<<"Brak rozwiazan"<<endl;
      break;
    }
  }
}