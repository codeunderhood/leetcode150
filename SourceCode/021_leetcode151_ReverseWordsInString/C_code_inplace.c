#include <stdio.h>
#include <string.h>

// Function to reverse characters from left to right
void reverse(char *s, int left, int right) {

    while (left < right) {

        char temp = s[left];
        s[left] = s[right];
        s[right] = temp;

        left++;
        right--;
    }
}

void reverseWords(char *s) {

    int n = strlen(s);

    // STEP 1: Reverse whole string
    reverse(s, 0, n - 1);

    int start = 0;
    int end = 0;

    // STEP 2: Reverse each word
    while (start < n) {

        // Skip spaces
        while (start < n && s[start] == ' ')
            start++;

        end = start;

        // Find end of word
        while (end < n && s[end] != ' ')
            end++;

        // Reverse current word
        reverse(s, start, end - 1);

        start = end;
    }

    // STEP 3: Remove extra spaces
    int i = 0;
    int j = 0;

    while (j < n) {

        // Skip spaces
        while (j < n && s[j] == ' ')
            j++;

        // Copy word
        while (j < n && s[j] != ' ') {
            s[i++] = s[j++];
        }

        // Skip spaces after word
        while (j < n && s[j] == ' ')
            j++;

        // Add one space if more words exist
        if (j < n)
            s[i++] = ' ';
    }

    s[i] = '\0';
}

int main() {

    char s[] = "  the   sky is blue  ";

    reverseWords(s);

    printf("%s", s);

    return 0;
}
