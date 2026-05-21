#include <stdio.h>
#include <string.h>

void intToRoman(int num, char *result) {

    // Roman values
    int values[] = {
        1000, 900, 500, 400,
        100, 90, 50, 40,
        10, 9, 5, 4, 1
    };

    // Roman symbols
    char *symbols[] = {
        "M", "CM", "D", "CD",
        "C", "XC", "L", "XL",
        "X", "IX", "V", "IV", "I"
    };

    // Initially empty string
    result[0] = '\0';

    // Traverse all values
    for(int i = 0; i < 13; i++) {

        // Keep using same symbol while possible
        while(num >= values[i]) {

            // Append Roman symbol
            strcat(result, symbols[i]);

            // Subtract value
            num -= values[i];
        }
    }
}

int main() {

    int num = 3749;

    char result[50];

    intToRoman(num, result);

    printf("Roman Numeral: %s\n", result);

    return 0;
}
