#include <stdio.h>
#include <stdlib.h>

// comparator for qsort
int cmp(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int hIndex(int* citations, int n) {
    qsort(citations, n, sizeof(int), cmp);

    int h = 0;

    // traverse from largest to smallest
    for (int i = n - 1; i >= 0; i--) {
        int papers_with_at_least = n - i;

        if (citations[i] >= papers_with_at_least) {
            h = papers_with_at_least;
        } else {
            break;
        }
    }

    return h;
}

int main() {
    int citations[] = {3, 0, 6, 1, 5};
    int n = sizeof(citations) / sizeof(citations[0]);

    printf("H-Index: %d\n", hIndex(citations, n));
    return 0;
}
