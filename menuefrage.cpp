#include "menuefrage.h"
#include "riemen.h"

int MenueFrage(void)
{
int frage = 18, i;
std::string wastun = "";
std::string erge[16] = {"0", "1", "2", "3", "4", "5", "6", "7", "8", "9", "10","11","12","13","14","15"};

std::cout << std::endl << "Ihre Wahl: ";
std::cin >> wastun; // frage

for (i = 0; i < 16; i++)
  {
   if (wastun.compare(erge[i]) == 0)
   {
    frage = i;
    break;
   }
}
clpuf();

return frage;
}