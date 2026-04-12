#include <stdio.h>
#include <stdlib.h>

// Swap helper
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

//////////////////////////////
// TRANSPOSE (common step)
//////////////////////////////
void transpose(int** matrix, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            swap(&matrix[i][j], &matrix[j][i]);
        }
    }
}

//////////////////////////////
// REVERSE EACH ROW
//////////////////////////////
void reverseRows(int** matrix, int n) {
    for (int i = 0; i < n; i++) {
        int left = 0, right = n - 1;
        while (left < right) {
            swap(&matrix[i][left], &matrix[i][right]);
            left++;
            right--;
        }
    }
}

//////////////////////////////
// REVERSE EACH COLUMN
//////////////////////////////
void reverseColumns(int** matrix, int n) {
    for (int j = 0; j < n; j++) {
        int top = 0, bottom = n - 1;
        while (top < bottom) {
            swap(&matrix[top][j], &matrix[bottom][j]);
            top++;
            bottom--;
        }
    }
}

//////////////////////////////
// REVERSE WHOLE MATRIX (180° helper)
//////////////////////////////
void reverseWholeMatrix(int** matrix, int n) {
    int top = 0, bottom = n - 1;

    while (top < bottom) {
        for (int j = 0; j < n; j++) {
            swap(&matrix[top][j], &matrix[bottom][j]);
        }
        top++;
        bottom--;
    }

    // Now reverse each row
    reverseRows(matrix, n);
}

//////////////////////////////
// 90° CLOCKWISE
//////////////////////////////
void rotate90(int** matrix, int n) {
    transpose(matrix, n);
    reverseRows(matrix, n);
}

//////////////////////////////
// 180° ROTATION
//////////////////////////////
void rotate180(int** matrix, int n) {
    reverseWholeMatrix(matrix, n);
}

//////////////////////////////
// 270° CLOCKWISE
//////////////////////////////
void rotate270(int** matrix, int n) {
    transpose(matrix, n);
    reverseColumns(matrix, n);
}

//////////////////////////////
// PRINT MATRIX
//////////////////////////////
void printMatrix(int** matrix, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

//////////////////////////////
// MAIN
//////////////////////////////
int main() {
    int n = 3;

    // allocate matrix
    int** matrix = (int**)malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++) {
        matrix[i] = (int*)malloc(n * sizeof(int));
    }

    // initialize matrix
    int val = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            matrix[i][j] = val++;
        }
    }

    printf("Original Matrix:\n");
    printMatrix(matrix, n);

    // Choose ONE to test:

    // rotate90(matrix, n);
    // rotate180(matrix, n);
    rotate270(matrix, n);

    printf("\nAfter Rotation:\n");
    printMatrix(matrix, n);

    return 0;
}
