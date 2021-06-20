#include "riemen.h"

double riemenlaenge(struct riemenantrieb *rit)
{
  rit->rgd = rit->gd / 2;       // Radius grosses Riemenrad
  rit->rkd = rit->kd / 2;       // Radius kleines Riemenrad
  rit->i = rit->gd / rit->kd;   // Radiusdifferenz

  // Bei kleinen Riemenrad  Umschlingungswinkel englisch: wrap angle
rit->Umschlingungswinkel = 2* radtograd(acos(((rit->gd-rit->kd) /(2* rit->A))));

  rit->alpha = (180 - rit->Umschlingungswinkel) / 2;             // Umschlingungswinkel kleines Riemenrad
  rit->beta = 360 - rit->Umschlingungswinkel;                    // Umschlingungwinkel grosses Riemenrad
  rit->Ua = ((rit->kd * M_PI) * rit->Umschlingungswinkel) / 360; // Umschlingungsumfang kleines Riemenrad
  rit->Ub = ((rit->gd * M_PI) * rit->beta) / 360;                // Umschlingungsumfang grosses Riemenrad


  rit->l1 = rit->A * (grad_sin(rit->beta / 2));  // EIN Teilstueck l1 berechnen

  rit->lx = rit->Ua + rit->Ub+ (2* rit->l1);   // Alle 4 Teile zusammenrechnen

  // Formel aus dem Tabellenbuch --->> Formel stimmt!
  rit->xu = ((M_PI * (rit->gd + rit->kd)) / 2) + ( 2 * rit->A * grad_sin(rit->beta / 2)) + (((M_PI * rit->alpha) / 180)* (rit->gd - rit->kd));

  rit->A_gd = get_FlaecheKreisteil(rit->gd, rit->beta);
  rit->A_kd = get_FlaecheKreisteil(rit->kd, rit->Umschlingungswinkel);
  
  
  // Errechnung der beiden Sehnenlaengen
  rit->S_gd = rit->gd * grad_cos(rit->alpha); //.alpha;
  rit->S_kd = rit->kd * grad_cos(rit->alpha); //.alpha;
  rit->S_Trazez = (rit->S_gd + rit->S_kd) / 2;
  rit->A_Trapez = rit->S_Trazez * rit->A;
   

  return rit->lx;
}

void ShowErgebnisse(struct riemenantrieb rit)
{
std::cout << "\nD=" << rit.gd << "  d=" << rit.kd << "  A=" << rit.A << std::endl;
std::cout << "Uebersetzungsverhaeltnis i = Dm/dm =" << rit.i << std::endl;
std::cout << "Umschlingungswinkel dm= " << std::setprecision(9) << rit.Umschlingungswinkel << "° Grad" << std::endl;
std::cout << "Umschlingungswinkel Dm= " << std::setprecision(9) << rit.beta << "° Grad" << std::endl;
std::cout << "alpha........= " << std::setprecision(9) << rit.alpha << std::endl;
std::cout << "l1 (Leange einer Schraege).....= " << std::setprecision(9) << rit.l1 << std::endl;
std::cout << "Mittlere Riemenlaenge:" <<  std::endl;
std::cout << "xu...........= " << std::setprecision(9) << rit.xu << std::endl;
std::cout << "lx...........= " << std::setprecision(9) << rit.lx << std::endl;
std::cout << "Teilflaeche grosses Riemenrad..= " << std::setprecision(9) << rit.A_gd << std::endl;
std::cout << "Teilflaeche kleines Riemenrad..= " << std::setprecision(9) << rit.A_kd << std::endl;
std::cout << "Sehnenlaenge grosses Riemenrad.= " << std::setprecision(9) << rit.S_gd << std::endl;
std::cout << "Sehnenlaenge kleines Riemenrad.= " << std::setprecision(9) << rit.S_kd << std::endl;
std::cout << "mittlere Breite des Trapez.....= " << std::setprecision(9) << rit.S_Trazez << std::endl;
std::cout << "Flaeche des Trapez.............= " << std::setprecision(9) << rit.A_Trapez << std::endl;
}

// Loesche den Tastaturpuffer 'Essensreste aufraeumen'
void clpuf(void)
{
while (getc(stdin) != '\n')
    ;
}


int get_diameters(struct riemenantrieb *rit, int berechnungsart)
{
int fehlertest = 0;

if(berechnungsart == 2)
std::cout << "Drehzahlberechnung: Bitte nur einen Durchmesser zur desser Berechnung auf Null setzen!" << std::endl;
std::cout << "Dm grosses Riemenrad: ";
std::cin >> rit->gd;
std::cout << "dm kleines Riemenrad: ";
std::cin >> rit->kd;

    if(berechnungsart == 1)
     {
       if(rit->gd <= 0)
        {
         std::cout << "Fehlerhafte Eingabe Dm grosses Riemenrad" << std::endl;
          fehlertest = 8;
        }
        if(rit->kd <= 0)
         {
          std::cout << "Fehlerhafte Eingabe dm kleines Riemenrad" << std::endl;
           fehlertest = 8;
        }
      }
   else if(berechnungsart == 2)
    {
      if((rit->gd <= 0) && (rit->kd <= 0))
        {
         std::cout << "Fehlerhafte Eingabe beider Durchmesser" << std::endl;
          fehlertest = 8;
        }
        if(rit->kd < 0)
         {
          std::cout << "Fehlerhafte Eingabe dm kleines Riemenrad < 0" << std::endl;
           fehlertest = 8;
         }
        if(rit->gd < 0)
         {
          std::cout << "Fehlerhafte Eingabe dm grosses Riemenrad < 0" << std::endl;
           fehlertest = 8;
         }
     }

return fehlertest;
}

int get_Achsabstand(struct riemenantrieb *rit)
{
int fehlertest = 0;
std::cout << "Achsabstand.........: ";
std::cin >> rit->A;
if((rit->A <= 0) || (rit->A <= ((rit->gd +rit->kd) / 2)))
  {
   std::cout << "Fehlerhafte Eingabe Achsabstand: kleiner/gleich (Dm + dm) / 2" << std::endl;
   fehlertest = 8;
  }
return fehlertest;
}

int get_Drehzahl(struct riemenantrieb *rit)
{
int fehlertest = 0;

    std::cout << "Drehzahl n1 an dm: ";
    std::cin >> rit->n1;
    std::cout << "Drehzahl n2 an Dm: ";
    std::cin >> rit->n2;

    if((rit->n1 <= 0) && (rit->n2 <= 0))
     {
      std::cout << "n1 an dm= " << rit->n1<< std::endl;
      std::cout << "n2 an Dm= " << rit->n1<< std::endl;
      std::cout << "Fehlerhafte Eingabe Drehzahl: Bitte eine Drehzahlangeben" << std::endl;
      fehlertest = 8;
     }

return fehlertest;
}

void calc_n_und_Dd(struct riemenantrieb *rit)
{
         // Antriebsformel: n1* dm = n2 * Dm
         // Antriebsformel: rit.n1* rit.kd = rit.n2 * rit.gd
         // Abschnitt aus Drehzahlen Durchmesser berechnen
         if ((rit->n1 > 0) && (rit->n2 > 0) && (rit->kd > 0))    // Aus n1, n2, d1  ->>d2
         {
          rit->gd = (rit->n1* rit->kd) / rit->n2;
         }
         if ((rit->n1 > 0) && (rit->n2 > 0) && (rit->gd > 0))    // Aus n1, n2, d2  ->>d1
         {
          rit->kd = (rit->n2* rit->gd) / rit->n1;
         }
         // Abschnitt aus Drehzahlen und Durchmesserangaben fehlende Angaben berechnen
         // Aus dm, Dm und n1  berechne n2
         if ((rit->kd > 0) && (rit->gd > 0) && (rit->n1 > 0))    // Aus d1, d2, n1  ->>n2
         {
          rit->n2 = rit->n1* rit->kd / rit->gd;
         }
         // Aus dm, Dm und n2  berechne n1
         if ((rit->gd > 0) && (rit->gd > 0) && (rit->n2 > 0))    // Aus d1, d2, n2  ->>n1
         {
          rit->n1 = rit->n2 * rit->gd / rit->kd;
         }
         // Aus dm, n2 und n1  berechne Dm
         if ((rit->kd > 0) && (rit->n1 > 0) && (rit->n2 > 0))    // Aus d1, n1, n2  ->>d2
         {
          rit->gd = rit->n1 * rit->kd / rit->n2;
         }
         // Aus Dm, n2 und n1  berechne dm
         if ((rit->gd > 0) && (rit->gd > 0) && (rit->n1 > 0))    // Aus d2, n1, n2  ->>d1
         {
          rit->kd = rit->n2 * rit->gd / rit->n1;
         }
         rit->i = rit->n1 / rit->n2;
}

double get_FlaecheKreisteil(double dmr, double winkel)
{
 double erge = 0;
 
 erge = (dmr * dmr * M_PI  * winkel)/ (4 * 360);
 
 return erge;
}