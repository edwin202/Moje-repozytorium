#include <iostream>
#include <conio.h>
#include <string>
#include <fstream>

using namespace std;

struct vinyle
{
  string autor;
  string tytul;
  string wytwornia;
  string styl;
};

short i;             // zmienna przechowujaca ilosc plyt
vinyle vinyl[200];   //200 elementowa tablica struktur

void Dodaj();        //deklaruje funkcje
void Zobacz();
void Zapisz();
void Wczytaj();
void Usun();
void Edytuj();


int main()
{
  cout<< "*******************\n"
  "****Spis Vinyli*****\n"              // nazwa mojego programu
  "*****by Siwy.*******\n"
  "*******************\n";
  cout << "\n\n\n";
  char wybor;

  do
  {
    cout <<"Aktualnie posiadasz "<<i<<" Plyt/e"<<endl;
    cout <<"1. Dodaj Plyte "<<endl;
    cout <<"2. Zobacz wszystkie plyty "<<endl;
    cout <<"3. Zapisz wprowadzone plyty "<<endl;
    cout <<"4. Wczytaj plyty z bazy "<<endl;
    cout <<"5. Usun plyte "<<endl;
  cout <<"6. Edytuj plyte "<<endl;

    cout <<"ESC - Koniec programu "<<endl<<endl;

    wybor = getch(); 

    switch (wybor)
    {
      case 49: Dodaj();
      break;
      case 50: Zobacz();
      break;
      case 51: Zapisz();
      break;
      case 52: Wczytaj();
      break;
      case 53: Usun();
      break;
      case 54: Edytuj();
      break;
    }

    system("cls");     
  } while (wybor != 27);



 // system("pause");
  return 0;   
}   // koniec main
void Dodaj()
{
  cout <<"Podaj autora plyty: \n";       ////przypisanie wartoœci x w obiekcie vinyl
  cin >>vinyl[i].autor;

  cout <<"Podaj tytul plyty: \n";
  cin >>vinyl[i].tytul;

  cout <<"Podaj wytwornie: \n";
  cin >>vinyl[i].wytwornia;

  cout <<"Podaj styl: \n";
  cin >>vinyl[i].styl;

  cin.ignore();

  i++;

  cout <<". Wcisnij ENTER! :)";
  getchar();
}
void Zobacz()
{
  if ( i != 0)                             //musi byc conajmniej 1 element do wypisania
  {
    for (short j = 0; j < i; j++)   //j jest indeksem umozliwiajacym wypisywanie kolejnych elementow.wypisuje od 0 do i
    {                               //j<i wyswietlanie prawidlowej wartosci   i = j-1
      cout <<"xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx"<<endl;
      cout <<"x     Vinyl nr "<<j+1<<": "<<endl;
      cout <<"x     Autor: "<<vinyl[j].autor<<endl; 
      cout <<"x     Tutul: "<<vinyl[j].tytul<<endl;
      cout <<"x     Wytwornia: "<<vinyl[j].wytwornia<<endl;
      cout <<"x     Styl: "<<vinyl[j].styl<<endl;
      cout <<"x";
      cout <<"xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx"<<endl;
     
     
    }
  }
  else
  cout <<"Nie ma zadnej plyty w bazie!!"; 

  cout <<"Nacisnij ENTER";

  getchar();
}

void Zapisz()
{
  ofstream plik("plyty.txt", ios::out | ios::trunc);

  plik <<i<<"\n";

  for (short j = 0; j < i; j++)
  {
    plik <<vinyl[j].autor<<endl;
    plik <<vinyl[j].tytul<<endl;
    plik <<vinyl[j].wytwornia<<endl;
    plik <<vinyl[j].styl<<endl;
  }

  cout <<"Dane zostaly zapisane! :). Wcisnij ENTER";

  getchar();     
}



void Wczytaj()
{
  ifstream plik("plyty.txt", ios::in);

  plik >> i;


  short j = 0;

  do
  {
    plik >>vinyl[j].autor;
    plik >>vinyl[j].tytul;
    plik >>vinyl[j].wytwornia;
    plik >>vinyl[j].styl;         
    j++;
  } while( !plik.eof() );

  cout <<"Wczytano dane. Nacisnij ENTER!";

  getchar();   
}

void Usun()
{
  short kogo;

  if (i != 0)
  {
    cout <<"Podaj numer plyty ktora chcesz usunac: ";
    cin >>kogo;
    cin.ignore();

    if (kogo > i)
    cout <<"Operacja nie powiodla sie. Brak plyty o takim numerze";
    else
    {
      for (short k = kogo; k < i; k++)    
      {
        vinyl[k-1].autor = vinyl[k].autor;   //polega na zastapieniu elementu , elementem nastepnym,  na nastepnie i--
        vinyl[k-1].tytul = vinyl[k].tytul;
        vinyl[k-1].wytwornia = vinyl[k].wytwornia;
        vinyl[k-1].styl = vinyl[k].styl;
      }
      i--;

      cout <<"Operacja zakonczyla sie sukcesem! plyta o numerze "<<kogo<<" zostala usunieta!";
      Zapisz();
    }

  }
  else
  {
    cout <<"Nie ma plyt w bazie!! Wcisnij ENTER!";
    getchar();
  }
}
 
void Edytuj()
{
  //short kogo;
        int kogo;

  if (i != 0)
  {
    cout <<"Podaj numer plyty ktora chcesz zmienic: ";
    cin >>kogo;
    cin.ignore();

    if (kogo > i)
    cout <<"Operacja nie powiodla sie. Brak plyty o takim numerze";
    else
    {
//jest -1 bo zakladam ze numeracja plyt jest taka jak w wypisaniu. Natiomiast
                // tablica zaczyna sie od zera.
cout <<"Podaj autora plyty: \n";
cin>>vinyl[kogo-1].autor;                                //jest -1 bo zakladam ze numeracja plyt jest taka jak w wypisaniu. Natiomiast
                                                        // tablica zaczyna sie od zera.
             cout <<"Podaj tytul plyty: \n";;
     cin>>vinyl[kogo-1].tytul;
   cout <<"Podaj wytwornie: \n";
     cin>>vinyl[kogo-1].wytwornia;
   cout <<"Podaj styl: \n";
     cin>>vinyl[kogo-1].styl;

 
      cout <<"Operacja zakonczyla sie sukcesem! plyta o numerze "<<kogo<<" zostala zmieniona!";
      Zapisz();
    }

  }
  else
  {
    cout <<"Nie ma plyt w bazie!! Wcisnij ENTER!";
    getchar();
  }
}