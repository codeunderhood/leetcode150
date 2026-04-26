#include <stdio.h>
#include <string.h>
#include <limits.h>

#define MAX 128

void minWindow(char *s, char *t, char *result) {
    int need[MAX] = {0}, window[MAX] = {0};

    int m = strlen(s);
    int n = strlen(t);

    // build frequency of t
    for (int i = 0; i < n; i++) {
        need[(int)t[i]]++;
    }

    int required = 0;
    for (int i = 0; i < MAX; i++) {
        if (need[i] > 0) required++;
    }

    int l = 0, r = 0;
    int formed = 0;

    int minLen = INT_MAX;
    int start = 0;

    while (r < m) {
        char c = s[r];
        window[(int)c]++;

        if (need[(int)c] > 0 &&
            window[(int)c] == need[(int)c]) {
            formed++;
        }

        // shrink window when valid
        while (l <= r && formed == required) {

            // ⭐ UPDATE STEP (important)
            if (r - l + 1 < minLen) {
                minLen = r - l + 1;
                start = l;
            }

            char leftChar = s[l];
            window[(int)leftChar]--;

            if (need[(int)leftChar] > 0 &&
                window[(int)leftChar] < need[(int)leftChar]) {
                formed--;
            }

            l++;
        }

        r++;
    }

    if (minLen == INT_MAX) {
        result[0] = '\0';
        return;
    }

    strncpy(result, s + start, minLen);
    result[minLen] = '\0';
}

int main() {
    char s[] = "ADOBECODEBANC";
    char t[] = "ABC";
    char result[1000];

    minWindow(s, t, result);

    printf("%s\n", result);

    return 0;
}
