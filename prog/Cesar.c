#include <stdio.h>
#include <string.h>
#include <locale.h>
#define ENG 26
#define RUS 32
 


int main ()
{
    setlocale(LC_ALL,"Russian");
    int n;
    printf ("Введите натуральное n: ");
    scanf ("%d", &n);
    getchar (); //нужен для того, чтобы поймать символ клавиши ENTER, нажатой при вводе числа n
    if (n < 1) return 0;
 encrypt (n);
 decipher (n);

 
    // Вывод содержимого файлов на экран
    printf("\nСодержимое файла int.txt:\n");
    printFileContents("int.txt");

    printf("\nСодержимое зашифрованного файла encryptout.txt:\n");
    printFileContents("encryptout.txt");

    printf("\nСодержимое расшифрованного файла decryptout.txt:\n");
    printFileContents("decryptout.txt");

    const char *fileName1 = "int.txt";
    const char *fileName2 = "decryptout.txt";

    if (compareFiles(fileName1, fileName2)) {
        printf("Содержимое файлов совпадает\n");
    } else {
        printf("Содержимое файлов не совпадает\n");
    }
    
    return 0;
} 