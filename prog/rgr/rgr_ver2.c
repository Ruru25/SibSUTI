#include <stdio.h>

void encryptFile(char* inputFile, char* outputFile) {
    FILE *input = fopen(inputFile, "r");
    FILE *output = fopen(outputFile, "w");

    if (input == NULL || output == NULL) {
        printf("Error opening files\n");
        return;
    }

    char c;
    while ((c = fgetc(input)) != EOF) {
        if (c >= 'A' && c <= 'Z') {
            c = 'Z' - (c - 'A');
        } else if (c >= 'a' && c <= 'z') {
            c = 'z' - (c - 'a');
        }
        fputc(c, output);
    }

    fclose(input);
    fclose(output);
}

void decryptFile(char* inputFile, char* outputFile) {
    FILE *input = fopen(inputFile, "r");
    FILE *output = fopen(outputFile, "w");

    if (input == NULL || output == NULL) {
        printf("Error opening files\n");
        return;
    }

    char c;
    while ((c = fgetc(input)) != EOF) {
        if (c >= 'A' && c <= 'Z') {
            c = 'Z' - (c - 'A');
        } else if (c >= 'a' && c <= 'z') {
            c = 'z' - (c - 'a');
        }
        fputc(c, output);
    }

    fclose(input);
    fclose(output);
}

int main() {
    encryptFile("input.txt", "encrypted.txt");
    decryptFile("encrypted.txt", "decrypted.txt");

    return 0;
}