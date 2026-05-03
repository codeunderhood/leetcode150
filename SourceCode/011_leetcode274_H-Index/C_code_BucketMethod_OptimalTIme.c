#include <stdio.h>
#include <stdlib.h>

int hIndex(int* citations, int n) {
    int *count = (int*)calloc(n + 1, sizeof(int));

    // Build frequency buckets
    for (int i = 0; i < n; i++) {
        if (citations[i] >= n)
            count[n]++;
        else
            count[citations[i]]++;
    }

    // Accumulate from right to left
    int total = 0;
    for (int i = n; i >= 0; i--) {
        total += count[i];
        if (total >= i) {
            free(count);
            return i;
        }
    }

    free(count);
    return 0;
}

// Example usage
int main() {
    int citations[] = {3, 0, 6, 1, 5};
    int n = sizeof(citations) / sizeof(citations[0]);

    printf("H-Index: %d\n", hIndex(citations, n));
    return 0;
}
