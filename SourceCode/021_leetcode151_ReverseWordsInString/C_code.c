#include <stdio.h>
#include <string.h>

#define MAX_WORDS 1000
#define MAX_LEN 10000

int main() {
    char s[MAX_LEN] = "  the   sky is blue  ";

    char words[MAX_WORDS][100];
    int count = 0;

    int i = 0;

    // Extract words
    while (s[i] != '\0') {

        // Skip spaces
        while (s[i] == ' ') {
            i++;
        }

        // If end reached
        if (s[i] == '\0')
            break;

        int j = 0;

        // Store characters of one word
        while (s[i] != ' ' && s[i] != '\0') {
            words[count][j++] = s[i++];
        }

        words[count][j] = '\0';
        count++;
    }

    // Print in reverse order
    for (i = count - 1; i >= 0; i--) {
        printf("%s", words[i]);

        if (i != 0)
            printf(" ");
    }

    return 0;
}
