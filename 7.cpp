#include <cstdlib>
#include <iostream>
#include <string>
#include <ctype.h>

using namespace std;

//nowy kom

int IloscLiter(string Imie);
bool Plec(string Imie, int IloscLiter);
string PoprawImie(string Imie);
bool SprawdzDane(string Imie);

//fsd
int main(int argc, char *argv[])
{
     string pImie;
     cout << " Podaj swoje imie: ";
     cin >> pImie;
     if(!SprawdzDane(pImie)){
          while(!SprawdzDane(pImie)){
          cout << " Podales bledne dane. Sprobuj jeszcze raz: ";
          cin >> pImie;
          }
     }
     cout << endl << " Czesc " << PoprawImie(pImie) << "! Moim zdaniem ";
     if(Plec(PoprawImie(pImie),IloscLiter(pImie))) cout << "jestes mezczyzna." << endl;
     else cout << "jestes kobieta." << endl;
    system("PAUSE");
    return EXIT_SUCCESS;
}

bool SprawdzDane(string Imie){
     int i=0; int a=0;
     while(Imie[i] != 0){
          if((Imie[i] < 'a' || Imie[i] > 'z') && (Imie[i] < 'A' || Imie[i] > 'Z') || (Imie[i] == 32)) a++;
          i++;
     }
     if(a>0) return false;
     else return true;
}

string PoprawImie(string Imie){
     int i=0;
     while(Imie[i] != '\0'){
          Imie[i] = tolower(Imie[i]);
          i++;
     }
     Imie[0] = toupper(Imie[0]);
     return Imie;
}

bool Plec(string Imie, int IloscLiter){
     if(Imie[IloscLiter] == 'a' && Imie == "Kuba") return true;
     if(Imie[IloscLiter] != 'a') return true;
     else return false;
}

int IloscLiter(string Imie){
     int i=0;
     while(Imie[i] != '\0') i++;
     return i-1;
}
 
