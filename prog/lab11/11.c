#include <stdio.h>
#include<stdlib.h>
#include<math.h>

struct Cone 
{
    double r; 
    double h; 
};


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

int main() 
{
    int N; 
    printf("Введите количество конусов: ");
    scanf("%d", &N);

    struct Cone* cones = (struct Cone*)malloc(N * sizeof(struct Cone)); 

  
    for (int i = 0; i < N; ++i) 
    {
        printf("Введите радиус основания и высоту для конуса %d: ", i + 1);
        scanf("%lf %lf", &cones[i].r, &cones[i].h);
    }

    for (int i = 0; i < N; ++i) 
    {
        printConeInfo(cones[i], i+1);
    }

    free(cones); 

    return 0;
}
