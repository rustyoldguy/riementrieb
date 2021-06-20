// riemenlaenge4 Berechung der mittleren Riemenlaenge eines Riementriebes
#include "riemen.h"
#include "menuefrage.h"

int main(int argc, char **argv)
{
riemenantrieb rit;

int quest = 8;

do
switch(quest)
{
  default:
       std::cout << "\nRiemenantrieb, Berechnung der mittleren Riemenlaenge V 0.5" << std::endl;
       std::cout << "Programmende.................0" << std::endl;
       std::cout << "Riemenlaenge Beispiel........1" << std::endl;
       std::cout << "Riemenlaenge eigene Angaben..2" << std::endl;
       std::cout << "Drehzahl berechnen...........3" << std::endl;
       quest = MenueFrage();

     break;


  case 0:
       std::cout << "Programm beendet" << std::endl;
       return 0;

  case 1:
        rit.A = 140;   // Wellenabstand
        rit.gd = 105;  // Durchmesser der großen Keilriemenscheibe
        rit.kd = 46;   // Durchmesser der kleinen Keilriemenscheibe
         riemenlaenge(&rit);
        ShowErgebnisse(rit);
           quest = 8;
      break;

  case 2:
        std::cout << "Berechnung der mittleren Riemenlaenge" << std::endl;
        quest = get_diameters(&rit, RIEMENLAENGE);
        if(quest != 0) break;
        quest = get_Achsabstand(&rit);
        if(quest != 0) break;
        riemenlaenge(&rit);
        ShowErgebnisse(rit);
        quest = 8;
      break;

   case 3:
        std::cout << "Berechnung der Drehzahl" << std::endl;
        get_diameters(&rit, DREHZAHLEN);
        quest = get_Drehzahl(&rit);
        if(quest != 0) break;
        calc_n_und_Dd(&rit);

        std::cout << "\nD=" << rit.gd << "  d=" << rit.kd << std::endl;
        std::cout << "n2=" << rit.n2 << "  n1=" << rit.n1 << std::endl;
        std::cout << "Uebersetzungsverhaeltnis i=" << rit.i << std::endl;

        quest = 8;
      break;


}while(quest != 0);
    return 0;
}


