#include <stdio.h>
#include <string.h>

// Function to find longest common prefix
char* longestCommonPrefix(char strs[][200], int strsSize) {

    // Static array to store answer
    static char prefix[200];

    // Edge case
    if (strsSize == 0) {
        prefix[0] = '\0';
        return prefix;
    }

    int i, j;

    // Traverse characters of first string
    for (i = 0; strs[0][i] != '\0'; i++) {

        char current = strs[0][i];

        // Compare with all other strings
        for (j = 1; j < strsSize; j++) {

            // Mismatch OR string ended
            if (strs[j][i] != current || strs[j][i] == '\0') {

                prefix[i] = '\0';
                return prefix;
            }
        }

        // Store matching character
        prefix[i] = current;
    }

    // End the prefix string
    prefix[i] = '\0';

    return prefix;
}

int main() {

    char strs[3][200] = {"flower", "flow", "flight"};

    printf("Longest Common Prefix: %s",
           longestCommonPrefix(strs, 3));

    return 0;
}
