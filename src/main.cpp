#include <iostream>
#include "Wektor.hh"
#include "Macierz.hh"
#include "UkladRownanLiniowych.hh"

using namespace std;

int main(){

  cout<<endl<<" Podaj macierz, ktorej elementy chcesz podniesc do kwadratu: "<<endl<<endl;
  UkladRownanLiniowych   UklRown;   // To tylko przykladowe definicje zmiennej
   Macierz M;//Macierz, ktorej elementy podnosimy do kwadratu
   cin>>M;
   M=M.Kwadrat();
   cout<<endl<<"Macierz z elementami podniesionymi do kwadratu:"<<endl<<endl<<M<<endl;
  cout << endl << " Start programu " <<  endl  <<  endl;
  cin>>UklRown;
  cout<<UklRown;
  switch (UklRown.oblicz_wynik()){

    case JEDNO_ROZWIAZANIE:
      cout<<"Rozwiazanie x = (x1, x2, x3):"<<endl<<endl;
      cout<<UklRown.get_Wek_wynikow()<<endl<<endl;
      cout<<"Wektor bledu Ax-b:"<<endl<<endl;
      cout<<UklRown.get_Wek_Bledow()<<endl<<endl;
      cout<<"Dlugosc wektora bledu ||Ax-b||:"<<endl<<endl;
      cout<<UklRown.get_Dl_Wek_Bledu()<<endl<<endl;
      break;

    case NIESKONCZENIE_WIELE_ROZWIAZAN:
    cout<<"NIESKONCZENIE_WIELE_RZOWIAZAN"<<endl;
    break;

    case BRAK_ROZWIAZAN:
    cout<<"Brak rozwiazan"<<endl;
    break;
  }
}
