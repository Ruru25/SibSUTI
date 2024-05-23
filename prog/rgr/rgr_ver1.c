#include <stdio.h>

void encryptFile(FILE *input, FILE *output) {
    char c;
    while ((c = fgetc(input)) != EOF) {
        if (c >= 'A' && c <= 'Z') {
            c = 'Z' - (c - 'A');
        } else if (c >= 'a' && c <= 'z') {
            c = 'z' - (c - 'a');
        }
        fputc(c, output);
    }
}

int main() {
    FILE *inputFile = fopen("input.txt", "r");
    FILE *outputFile = fopen("output.txt", "w");

    if (inputFile == NULL || outputFile == NULL) {
        printf("Error opening files.\n");
        return 1;
    }

    encryptFile(inputFile, outputFile);

    fclose(inputFile);
    fclose(outputFile);

    printf("File encrypted successfully.\n");

    return 0;
}