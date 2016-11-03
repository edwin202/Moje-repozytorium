#include <cstdlib>
#include <iostream>
#include <conio.h>
#include <string>
#include <fstream>
class Zwierze
{
   public:
      Zwierze()
      { }

      void jedz( )
      {
          for ( int i=0; i<5; ++i )
             std::cout << "Jem, Jem,Jem,Jem,Jem,Jem,Jem,Jem,Jem ";
      }

      void pij( )
      {
          for ( int i=0; i<5; ++i )
             std::cout << "Hlip, Hlip, Hlip, Hlip,";
      }

      void spij( )
      {
          std::cout << "zZZZZZZzZZZZZZZz zZZZZZZzZZZZZZZz \n";
      }
};

class Pies : public Zwierze
{
   public:
     Pies()
     { }

     void szczekaj()
     {
        std::cout << "Hal, Hal... Hal... Hal... Hal... Hal... Hal...";
     }
     
    //nadpisanie przeci¹¿enie 
     void jedz()
     {
        std::cout << " jemjemjemjemjemjemjemjemjemjemj";
     }

     void warcz()
     {
        std::cout << "Wrrrrrr... Wrrrrrr... ";
     }
};

class Kot : public Zwierze
{
   public:
     Kot()
     { }

     void mialcz()
     {
        std::cout << "Mial mial  mial...mial...mial...mial...mial...mial...mial...";
     }

     void naDrzewo()
     {
        std::cout << "Ide na drzewo... Ide na drzewo..";
     }
};





int main()
{
   Pies burek;
   Kot mruczek;
   char wybor; 
do
{
   std::cout << "\nMruczek mialcz 1 \n";
   std::cout << "Mruczek pij 2 \n";
   std::cout << "Mruczek spij 3 \n";
   std::cout << "Burek warcz 4 \n";
   std::cout << "Burek szczekaj 5 \n";
   std::cout << "Burek jedz 6 \n";
   wybor = getch(); 
   switch (wybor)
   {
    case 49: mruczek.mialcz();
    break; 
    case 50: mruczek.pij();
    break;
    case 51: mruczek.spij();
    break;
    case 52: burek.warcz();
    break;
    case 53: burek.szczekaj();
    break;
    case 54: burek.jedz();
    break;
   }
} while (wybor != 27);
  
      
  //int stop;
  //std::cin >> stop;
  return 0;
}