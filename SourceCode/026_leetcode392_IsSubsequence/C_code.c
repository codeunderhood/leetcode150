#include <stdio.h>
#include <stdbool.h>

bool isSubsequence(char *s, char *t) {
    int i = 0; // pointer for s
    int j = 0; // pointer for t

    while (t[j] != '\0') {
        if (s[i] != '\0' && s[i] == t[j]) {
            i++;
        }
        j++;
    }

    return s[i] == '\0';
}

int main() {
    char s[] = "abc";
    char t[] = "ahbgdc";

    if (isSubsequence(s, t))
        printf("true");
    else
        printf("false");

    return 0;
}
