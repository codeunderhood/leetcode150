#include <iostream>
#include <vector>
using namespace std;

// Swap helper
void swapVal(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

//////////////////////////////
// TRANSPOSE
//////////////////////////////
void transpose(vector<vector<int>> &matrix, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            swapVal(matrix[i][j], matrix[j][i]);
        }
    }
}

//////////////////////////////
// REVERSE EACH ROW
//////////////////////////////
void reverseRows(vector<vector<int>> &matrix, int n) {
    for (int i = 0; i < n; i++) {
        int left = 0, right = n - 1;
        while (left < right) {
            swapVal(matrix[i][left], matrix[i][right]);
            left++;
            right--;
        }
    }
}

//////////////////////////////
// REVERSE EACH COLUMN
//////////////////////////////
void reverseColumns(vector<vector<int>> &matrix, int n) {
    for (int j = 0; j < n; j++) {
        int top = 0, bottom = n - 1;
        while (top < bottom) {
            swapVal(matrix[top][j], matrix[bottom][j]);
            top++;
            bottom--;
        }
    }
}

//////////////////////////////
// 90° CLOCKWISE
//////////////////////////////
void rotate90(vector<vector<int>> &matrix, int n) {
    transpose(matrix, n);
    reverseRows(matrix, n);
}

//////////////////////////////
// 180° ROTATION
//////////////////////////////
void rotate180(vector<vector<int>> &matrix, int n) {
    reverseRows(matrix, n);
    reverseColumns(matrix, n);
}

//////////////////////////////
// 270° CLOCKWISE
//////////////////////////////
void rotate270(vector<vector<int>> &matrix, int n) {
    transpose(matrix, n);
    reverseColumns(matrix, n);
}

//////////////////////////////
// PRINT MATRIX
//////////////////////////////
void printMatrix(vector<vector<int>> &matrix) {
    for (auto &row : matrix) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << endl;
    }
}

//////////////////////////////
// MAIN
//////////////////////////////
int main() {
    int n = 3;

    vector<vector<int>> matrix = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    cout << "Original Matrix:\n";
    printMatrix(matrix);

    // Choose ONE:
    // rotate90(matrix, n);
    // rotate180(matrix, n);
    rotate270(matrix, n);

    cout << "\nAfter Rotation:\n";
    printMatrix(matrix);

    return 0;
}
