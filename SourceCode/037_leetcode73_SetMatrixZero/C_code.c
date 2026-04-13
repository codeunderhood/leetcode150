#include <stdio.h>
#include <stdlib.h>

void setZeroes(int** matrix, int m, int* matrixColSize) {
    int n = matrixColSize[0];
    int firstRowZero = 0, firstColZero = 0;

    // Check first row & column in one pass
    // set flags high, to use it later
    for (int i = 0; i < m; i++) {
        if (matrix[i][0] == 0) firstColZero = 1;
    }
    for (int j = 0; j < n; j++) {
        if (matrix[0][j] == 0) firstRowZero = 1;
    }

    // Mark rows and columns --> if any element is zero, mark that row and column as zero
    for (int i = 1; i < m; i++) {
        for (int j = 1; j < n; j++) {
            if (matrix[i][j] == 0) {
                matrix[i][0] = 0;
                matrix[0][j] = 0;
            }
        }
    }

    // Apply markers (combined logic, still one pass)
    // solve inner matrix --> make all its elements zero, if any of the 0th row/column element is zero
    // for example: if matrix[2][0] == 0, then make all 2,1 to 2,n elements zero for that row --> making that row zero
    // and when matrix[0][2] == 0, then make all 1,2 to n,2 elements as zero --> making column zero
    for (int i = 1; i < m; i++) {
        for (int j = 1; j < n; j++) {
            if (matrix[i][0] == 0 || matrix[0][j] == 0)
                matrix[i][j] = 0;
        }
    }

    // Handle first row
    // at last make entire first row zero, if any of the elements was zero originally
    if (firstRowZero) {
        for (int j = 0; j < n; j++)
            matrix[0][j] = 0;
    }

    // Handle first column
    // at last make entire column as zero, if any element was zero originally 
    if (firstColZero) {
        for (int i = 0; i < m; i++)
            matrix[i][0] = 0;
    }
}

// Helper to print matrix
void printMatrix(int** matrix, int m, int n) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int m = 3, n = 3;

    // Allocate matrix
    int** matrix = (int**)malloc(m * sizeof(int*));
    for (int i = 0; i < m; i++) {
        matrix[i] = (int*)malloc(n * sizeof(int));
    }

    // Initialize matrix
    int data[3][3] = {
        {1, 1, 1},
        {1, 0, 1},
        {1, 1, 1}
    };

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            matrix[i][j] = data[i][j];
        }
    }

    int matrixColSize[3] = {n, n, n};

    printf("Original Matrix:\n");
    printMatrix(matrix, m, n);

    // Call function
    setZeroes(matrix, m, matrixColSize);

    printf("\nAfter setZeroes:\n");
    printMatrix(matrix, m, n);

    // Free memory
    for (int i = 0; i < m; i++) {
        free(matrix[i]);
    }
    free(matrix);

    return 0;
}
