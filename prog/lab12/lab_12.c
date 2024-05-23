#include <stdio.h>
#include <stdlib.h>
#include <math.h>



struct Cone 
{
    double r;
    double h;
};

double calculateVolume(struct Cone cone) 
{
    return M_PI * cone.r * cone.r * cone.h / 3;
}

double calculateSurfaceArea(struct Cone cone) 
{
    double l = sqrt(cone.r * cone.r + cone.h * cone.h);
    return M_PI * cone.r * (cone.r + l);
}

int main() 
{
    int N;
    printf("Введите количество конусов: ");
    scanf("%d",&N);

    // Cone *cones = new Cone[N];
    struct Cone *cones = malloc(N * sizeof(struct Cone));


    for (int i = 0; i < N; i++) 
    {
        double radius, height;
        printf("Введите радиус основания конуса %d : ", i+1);
        scanf("%lf",&radius);
        cones[i].r = radius;
        printf("Введите высоту конуса %d : ", i+1);
        scanf("%lf",&height);
        cones[i].h = height;
    }

    printf("Результаты:\n");
    for (int i = 0; i < N; i++) 
    {
        printf("Конус %d - Объем: %.2lf, Площадь поверхности: %.2lf\n", i+1, calculateVolume(cones[i]), calculateSurfaceArea(cones[i]));
    }

    // delete[] cones;
    free(cones);
    return 0;
}
