#include "riemen.h"

// Wandelt Bogenmass in Grad um
double radtograd(double boma)
{
double grad, pi = M_PI;

grad = ((boma * 180) / pi);
return grad;
}

// Wandelt grad in Bogenmass um
double bogenmass(double grad)
{
double boma, pi = M_PI;

boma = (grad * pi)  / 180;
return boma;
}

double get_tanwert(double lfatan)
{
double boma, grad;
boma = atan(lfatan);
grad = radtograd(boma);

return grad;
}

double grad_sin(double grad)
{
double boma, sinwert;

boma = bogenmass(grad);
sinwert = sin(boma);

return sinwert;
}

double grad_cos(double grad)
{
double boma, coswert;

boma = bogenmass(grad);
coswert = cos(boma);

return coswert;
}

