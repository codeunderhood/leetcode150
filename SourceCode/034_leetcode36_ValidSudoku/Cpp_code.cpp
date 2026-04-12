#include <iostream>
using namespace std;

// 2D Array Method
bool isValidSudoku_Array(char board[9][9]) {
    int rows[9][9] = {0};
    int cols[9][9] = {0};
    int boxes[9][9] = {0};

    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {

            if (board[i][j] == '.') continue;

            int num = board[i][j] - '1';
            int boxIndex = (i / 3) * 3 + (j / 3);

            if (rows[i][num] || cols[j][num] || boxes[boxIndex][num]) {
                return false;
            }

            rows[i][num] = 1;
            cols[j][num] = 1;
            boxes[boxIndex][num] = 1;
        }
    }

    return true;
}

// Bitmask Method
bool isValidSudoku_Bitmask(char board[9][9]) {
    int rows[9] = {0};
    int cols[9] = {0};
    int boxes[9] = {0};

    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {

            if (board[i][j] == '.') continue;

            int num = board[i][j] - '1';
            int mask = 1 << num;
            int boxIndex = (i / 3) * 3 + (j / 3);

            if ((rows[i] & mask) ||
                (cols[j] & mask) ||
                (boxes[boxIndex] & mask)) {
                return false;
            }

            rows[i] |= mask;
            cols[j] |= mask;
            boxes[boxIndex] |= mask;
        }
    }

    return true;
}

// Main Function
int main() {
    char board[9][9] = {
        {'5','3','.','.','7','.','.','.','.'},
        {'6','.','.','1','9','5','.','.','.'},
        {'.','9','8','.','.','.','.','6','.'},
        {'8','.','.','.','6','.','.','.','3'},
        {'4','.','.','8','.','3','.','.','1'},
        {'7','.','.','.','2','.','.','.','6'},
        {'.','6','.','.','.','.','2','8','.'},
        {'.','.','.','4','1','9','.','.','5'},
        {'.','.','.','.','8','.','.','7','9'}
    };

    cout << "2D Array Method: ";
    cout << (isValidSudoku_Array(board) ? "Valid Sudoku" : "Invalid Sudoku") << endl;

    cout << "Bitmask Method: ";
    cout << (isValidSudoku_Bitmask(board) ? "Valid Sudoku" : "Invalid Sudoku") << endl;

    return 0;
}
