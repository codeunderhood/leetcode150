#include <stdio.h>
#include <stdbool.h>

// Method 1: Using 2D Arrays
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

// Method 2: Using Bitmask
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

    // Call Array Method
    if (isValidSudoku_Array(board))
        printf("Array Method: Valid Sudoku\n");
    else
        printf("Array Method: Invalid Sudoku\n");

    // Call Bitmask Method
    if (isValidSudoku_Bitmask(board))
        printf("Bitmask Method: Valid Sudoku\n");
    else
        printf("Bitmask Method: Invalid Sudoku\n");

    return 0;
}
