#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

double factorial(int n) 
{
    if (n == 0 || n == 1) {
        return 1;
    } else {
        return n * factorial(n - 1);
    }
}

double cosSeries(double x, double epsilon, int n) 
{
    double term = pow(-1, n) * pow(x, 2 * n) / factorial(2 * n);
    if (fabs(term) < epsilon) {
        return term;
    } else {
        return term + cosSeries(x, epsilon, n + 1);
    }
}

int main() 
{
    srand(time(NULL));
    double x = (double) rand() / RAND_MAX * 10; 
    double epsilon = 1e-3;
    int n = 0;

    double sum = cosSeries(x, epsilon, n);
    printf("Значение cos(%lf): %lf\n", x, sum);
    printf("Число членов ряда, вошедших в сумму: %d\n", n);

    return 0;
}