#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

// Function to generate a random character from a given character set
char getRandomChar(const char *charSet, int charSetLength) {
    return charSet[rand() % charSetLength];
}

// Function to generate a random password
void generatePassword(int length) {
    char *digits = "0123456789";
    int digitLength = strlen(digits);
    char *lower = "abcdefghijklmnopqrstuvwxyz";
    int lowerLength = strlen(lower);
    char *upper = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    int upperLength = strlen(upper);
    char *symbols = "~`|•√π÷×§∆€¥$¢^°=\\%©®™✓[]><";
    int symbolLength = strlen(symbols);

    char *password = malloc(length + 1);

    for (int i = 0; i < length; i++) {
        int charType = rand() % 4;
        switch (charType) {
            case 0:
                password[i] = getRandomChar(digits, digitLength);
                break;
            case 1:
                password[i] = getRandomChar(lower, lowerLength);
                break;
            case 2:
                password[i] = getRandomChar(upper, upperLength);
                break;
            default:
                password[i] = getRandomChar(symbols, symbolLength);
                break;
        }
    }

    password[length] = '\0';
    printf("password: %s\n", password);

    free(password);
}

int main() {
    while (1) {
        printf("length: ");
        int length;
        scanf("%d", &length);

        if (length <= 0) {
            printf("!! Length of the password cannot be equal to zero\n");
            return 1;
        }

        generatePassword(length);
    }

    return 0;
}
