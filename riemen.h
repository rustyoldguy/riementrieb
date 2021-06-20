#ifndef RIEMEN_INC_
#define RIEMEN_INC_ 1

#include <iostream>
#include <iomanip>
#include <math.h>

double radtograd(double boma);
double bogenmass(double grad);
double get_tanwert(double lfatan);
double grad_sin(double grad);
double grad_cos(double grad);
void clpuf(void);

#define RIEMENLAENGE 1
#define DREHZAHLEN 2


extern struct riemenantrieb{
double A;
double gd;
double kd;
double i;
double rgd;
double rkd;
double A_gd;
double A_kd;
double S_gd;
double S_kd;
double S_Trazez;
double A_Trapez;

double grad;
double boma;
double alpha;
double Umschlingungswinkel;
double beta;
double l1;
double Ua;
double Ub;
double lx;
double xu;

double n1; // Drehzahl kd
double n2; // Drehzahl gd

} rit;

double riemenlaenge(struct riemenantrieb *rit);
void ShowErgebnisse(struct riemenantrieb rit);
int get_diameters(struct riemenantrieb *rit, int berechnungsart);
int get_Achsabstand(struct riemenantrieb *rit);
int get_Drehzahl(struct riemenantrieb *rit);
void calc_n_und_Dd(struct riemenantrieb *rit);
double get_FlaecheKreisteil(double dmr, double winkel);

#endif