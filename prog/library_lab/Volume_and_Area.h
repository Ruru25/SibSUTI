#pragma once
#include <stdio.h>
#include<stdlib.h>
#include<math.h>

struct Cone 
{
    double r; 
    double h; 
};

double volume(struct Cone c);
double Area(struct Cone c) ;
void printConeInfo(struct Cone c, int number);