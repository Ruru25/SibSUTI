#include <iostream>              
#include <string>
#include <fstream>
using namespace std;
struct owners
{ string surname;
  string type;
  string color;
} car[3];
int num;
 
void write()
{ 
    owners LB;
    string type;
    string color;
    ofstream file ("Info.dat");
    cout <<"Enter number of owners: ";
    cin >>num;
    cout << "\n";
    for(int i = 0; i < num; i++)
    {      
        cout << "Enter surname: ";
        cin >> car[i].surname;
        cout << "Enter type of car: ";
        cin >> car[i].type;
        cout << "Enter color of car: ";
        cin >> car[i].color;
        cout << "\n"<< endl;
    }
    file.write((char*)&car,sizeof (*car));
    file.close();
}

int main ()
{
write();
}