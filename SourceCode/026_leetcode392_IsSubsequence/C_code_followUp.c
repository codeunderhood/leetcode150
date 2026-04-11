#include <stdio.h>
#include <string.h>

#define MAX 100000

int pos[26][MAX];
int size[26];

void preprocess(char *t) {
    int len = strlen(t);

    for (int i = 0; i < len; i++) {
        int idx = t[i] - 'a';
        pos[idx][size[idx]++] = i;
    }
}

// binary search for next index > prev
int findNext(int arr[], int n, int prev) {
    int l = 0, r = n - 1, ans = -1;

    while (l <= r) {
        int mid = (l + r) / 2;

        if (arr[mid] > prev) {
            ans = arr[mid];
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }

    return ans;
}

int isSubsequence(char *s) {
    int prev = -1;

    for (int i = 0; s[i] != '\0'; i++) {
        int c = s[i] - 'a';

        if (size[c] == 0) return 0;

        int next = findNext(pos[c], size[c], prev);

        if (next == -1) return 0;

        prev = next;
    }

    return 1;
}

int main() {
    char t[] = "ahbgdc";

    preprocess(t);

    printf("%d\n", isSubsequence("abc"));
    printf("%d\n", isSubsequence("axc"));

    return 0;
}
