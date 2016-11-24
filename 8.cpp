#include<;iostream>;
#include<;conio.h>;
#include <;fstream>;

//nowy kom

using namespace std;
int select;
int end;



//kom





int main()
{
    int end = 1;
    
    do{
    
    cout <;<; "\t\t\t\tWitaj!\n\n";
    cout <;<; "\t\tABY ZAKONCZYC WPISZ 100 I WCISNIJ ENTER\n\n";
    
    cout <;<; "Wybierz co ma zrobic program\n\n";
    cout <;<; "1. Uruchom WIERSZ POLECEN\t\t\t2. Uruchom EDYTOR REJESTRU\n";
    
    cout <;<; "\n\n\n\n\n\n"; 
    cin >;>; select;
    switch(select)
    {
                  case 1:
                       system("start cmd.exe");
                       cout <;<; "WIERSZ POLECEN URUCHOMIONY";
                       break;
                  case 2:
                       system("start regedit.exe");
                       cout <;<; "EDYTOR REJESTRU URUCHOMIONY";
                       break;
                  case 3:
                       system("ping 83.2.28.4");
                       break;
                  case 4:
                       cout <;<; "1\n\n";
                       break;
                  case 100:
                       system("start exit.exe");
                       break;
                  default:
                       cout <;<; "Nie ma takiej pozycji\n\n"; 
                       break;                 
    }  ;
    getch();;
    system("cls");;
    
    }while(end != 0);;
};
