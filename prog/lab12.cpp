#include <iostream>
#include <cmath>

using namespace std;

struct Cone 
{
    double r;
    double h;
};

double calculateVolume(Cone cone) 
{
    return M_PI * cone.r * cone.r * cone.h / 3;
}

double calculateSurfaceArea(Cone cone) 
{
    double l = sqrt(cone.r * cone.r + cone.h * cone.h);
    return M_PI * cone.r * (cone.r + l);
}

int main() 
{
    int N;
    cout << "Введите количество конусов: ";
    cin >> N;

    Cone *cones = new Cone[N];

    for (int i = 0; i < N; i++) 
    {
        cout << "Введите радиус основания конуса " << i+1 << ": ";
        cin >> cones[i].r;
        cout << "Введите высоту конуса " << i+1 << ": ";
        cin >> cones[i].h;
    }

    cout << "Результаты:n";
    for (int i = 0; i < N; i++) 
    {
        cout << "Конус " << i+1 << " - Объем: " << calculateVolume(cones[i]) << ", Площадь поверхности: " << calculateSurfaceArea(cones[i]) << endl;
    }

    delete[] cones;

    return 0;
}
