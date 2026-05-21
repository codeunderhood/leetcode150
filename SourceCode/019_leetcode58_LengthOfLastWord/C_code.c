#include <stdio.h>
#include <string.h>

int lengthOfLastWord(char* s) {

    int i = strlen(s) - 1;
    int count = 0;

    // Step 1: Skip trailing spaces
    while(i >= 0 && s[i] == ' ') {
        i--;
    }

    // Step 2: Count characters of last word
    while(i >= 0 && s[i] != ' ') {
        count++;
        i--;
    }

    return count;
}

int main() {

    char s[] = "Hello World";

    printf("%d", lengthOfLastWord(s));

    return 0;
}
