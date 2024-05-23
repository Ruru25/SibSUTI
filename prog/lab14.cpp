#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <string>
using namespace std;


// Генерирует случайную букву маленького английского алфавита
char getRandomChar() {
    return 'a' + rand() % 26;
}

string reverse_string(string str)
{
    int len = str.length();
    string rev_str;
    for(int i = len-1; i >= 0; i--)
    {
        rev_str += str[i];
    }
    return rev_str;
}

int main() {
    // Генерируем случайное количество строк от 1 до 10
    srand(time(0));
    int numLines = rand() % 100 + 1;

    // Открываем файл для записи
    ofstream file("input.txt");
    

    int num_max_len = 0;
    string stroka;

    // Заполняем файл автоматически
    for (int i = 1; i <= numLines; i++) 
    {
        string line;
        int lineLength = rand() % 20 + 1;  // Случайная длина строки от 1 до 20 символов
        for (int j = 0; j < lineLength; j++) {
            line += getRandomChar();
        }
        file << line << endl;
        if(stroka.length() < line.length())//поиск самой длинной строки
        {
            num_max_len = i;
            stroka = line;
        }
    }
 
    file.close();

    string stroka1 = reverse_string(stroka);
    cout<<stroka<<"\n"<<num_max_len<<endl;

    ifstream file2("input.txt");
    ofstream file1("uotput.txt");
    string line;
    while(file2)
    {
        getline(file2, line);
        if(line == stroka)
        {
            file1<<stroka1<<endl;
        }
        else
        {
            file1<<line<<endl;
        }
    }

    file2.close();
    file1.close();

    cout << "Файл успешно создан и заполнен." << endl;

    return 0;
}