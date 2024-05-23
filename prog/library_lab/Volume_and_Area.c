#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "Volume_and_Area.h"


double volume(struct Cone c) 
{
    return (1.0 / 3.0) * 3.14 * c.r * c.r * c.h;
}

double Area(struct Cone c) 
{
    double s = sqrt(c.r * c.r + c.h * c.h); // длина образующей
    return 3.14 * c.r * (c.r + s);
}

void printConeInfo(struct Cone c, int number) 
{
    printf("Объем конуса %d: %lf\n", number, volume(c));
    printf("Площадь поверхности конуса %d: %lf\n", number, Area(c));
}
