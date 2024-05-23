#include <stdio.h>
#include "Function.h"

int main() 
{
    encryptFile("input.txt", "encrypted.txt");
    decryptFile("encrypted.txt", "decrypted.txt");
}
