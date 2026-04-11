#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>

bool isPalindrome(char* s) {
    int i = 0;
    int j = strlen(s) - 1;

    while (i < j) {

        // skip non-alphanumeric from left
        while (i < j && !isalnum(s[i])) i++;

        // skip non-alphanumeric from right
        while (i < j && !isalnum(s[j])) j--;

        // compare (case-insensitive)
        if (tolower(s[i]) != tolower(s[j])) {
            return false;
        }

        i++;
        j--;
    }

    return true;
}

/* Test */
int main() {
    char s[] = "A man, a plan, a canal: Panama";

    if (isPalindrome(s)) {
        printf("True\n");
    } else {
        printf("False\n");
    }

    return 0;
}
