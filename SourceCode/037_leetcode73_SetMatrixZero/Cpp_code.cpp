#include <iostream>
#include <vector>
using namespace std;

void setZeroes(vector<vector<int>>& matrix) {
    int m = matrix.size();
    int n = matrix[0].size();

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
void printMatrix(const vector<vector<int>>& matrix) {
    for (const auto& row : matrix) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << endl;
    }
}

int main() {
    vector<vector<int>> matrix = {
        {1, 1, 1},
        {1, 0, 1},
        {1, 1, 1}
    };

    cout << "Original Matrix:\n";
    printMatrix(matrix);

    setZeroes(matrix);

    cout << "\nAfter setZeroes:\n";
    printMatrix(matrix);

    return 0;
}
