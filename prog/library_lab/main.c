#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "Volume_and_Area.h"

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
