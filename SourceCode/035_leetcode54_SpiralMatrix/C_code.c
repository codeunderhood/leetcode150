#include <stdio.h>
#include <stdlib.h>

int* spiralOrder(int** matrix, int m, int n, int* returnSize) {
    int* result = (int*)malloc(m * n * sizeof(int));
    *returnSize = 0;

    int top = 0, bottom = m - 1;
    int left = 0, right = n - 1;

    while (top <= bottom && left <= right) {

        // ➡️ Left to Right
        for (int j = left; j <= right; j++) {
            result[(*returnSize)++] = matrix[top][j];
        }
        top++;

        // ⬇️ Top to Bottom
        for (int i = top; i <= bottom; i++) {
            result[(*returnSize)++] = matrix[i][right];
        }
        right--;

        // ⬅️ Right to Left
        if (top <= bottom) {
            for (int j = right; j >= left; j--) {
                result[(*returnSize)++] = matrix[bottom][j];
            }
            bottom--;
        }

        // ⬆️ Bottom to Top
        if (left <= right) {
            for (int i = bottom; i >= top; i--) {
                result[(*returnSize)++] = matrix[i][left];
            }
            left++;
        }
    }

    return result;
}

int main() {
    int m = 3, n = 3;

    // Allocate matrix dynamically
    int** matrix = (int**)malloc(m * sizeof(int*));
    for (int i = 0; i < m; i++) {
        matrix[i] = (int*)malloc(n * sizeof(int));
    }

    // Example input
    int val = 1;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            matrix[i][j] = val++;
        }
    }

    int returnSize;
    int* result = spiralOrder(matrix, m, n, &returnSize);

    // Print result
    printf("Spiral Order: ");
    for (int i = 0; i < returnSize; i++) {
        printf("%d ", result[i]);
    }
    printf("\n");

    return 0;
}
