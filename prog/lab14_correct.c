#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_LINES 10
#define MAX_LENGTH 50

void generateRandomLines(FILE *file) {
    int numLines = rand() % MAX_LINES + 1;
    for (int i = 0; i < numLines; i++) {
        int length = rand() % MAX_LENGTH + 1;
        for (int j = 0; j < length; j++) {
            char ch = rand() % 26 + 'a';
            fputc(ch, file);
        }
        fputc('\n', file);
    }
}

void invertAndWrite(FILE *inputFile, FILE *outputFile) {
    char buffer[MAX_LENGTH];
    int maxLength = 0;
    char longestLine[MAX_LENGTH];

    while (fgets(buffer, MAX_LENGTH, inputFile) != NULL) {
        int length = strlen(buffer);
        if (length > maxLength) {
            maxLength = length;
            strcpy(longestLine, buffer);
        }
    }

    rewind(inputFile);

    while (fgets(buffer, MAX_LENGTH, inputFile) != NULL) {
        if (strlen(buffer) != maxLength) {
            fputs(buffer, outputFile);
        } else {
            for (int i = strlen(buffer) - 1; i >= 0; i--) {
                fputc(buffer[i], outputFile);
            }
            fputc('\n', outputFile);
        }
    }
}

int main() {
    srand(time(NULL));

    FILE *file1 = fopen("file1.txt", "w");
    if (file1 == NULL) {
        printf("Error opening file1.txt\n");
        return 1;
    }

    generateRandomLines(file1);

    fclose(file1);

    FILE *file2 = fopen("file1.txt", "r");
    FILE *file3 = fopen("file2.txt", "w");
    if (file2 == NULL || file3 == NULL) {
        printf("Error opening files\n");
        return 1;
    }

    invertAndWrite(file2, file3);

    fclose(file2);
    fclose(file3);

    return 0;
}