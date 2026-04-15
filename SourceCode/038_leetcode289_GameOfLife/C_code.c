/*
Encoding idea
We reuse the board in-place:
0 → dead → dead
1 → live → live
2 → live → dead
3 → dead → live

Key insight:
When counting neighbors, treat:
1 and 2 as originally live
0 and 3 as originally dead
*/
#include <stdio.h>
#include <stdlib.h>

// directions --> 8 directions. directions[0] --> first direction, direction[7] --> 8th direction
// directions[1] --> {-1,0}
// directions[1][0] = {-1} , directions[1][1] = {0} 
int directions[8][2] = {
    {-1, -1}, {-1, 0}, {-1, 1},
    {0, -1},           {0, 1},
    {1, -1},  {1, 0},  {1, 1}
};

int countLiveNeighbors(int** board, int m, int n, int row, int col) {
    int count = 0;

    for (int d = 0; d < 8; d++) {
        int newRow = row + directions[d][0]; // Example : d = 1 --> directions[1][0] = {-1}
        int newCol = col + directions[d][1]; // Example : d = 1 --> directions[1][1] = {0} 

        if (newRow >= 0 && newRow < m && newCol >= 0 && newCol < n) {
            if (board[newRow][newCol] == 1 || board[newRow][newCol] == 2) {
                count++; // 1,2 --> originally live
            }
        }
    }

    return count;
}

void gameOfLife(int** board, int boardSize, int* boardColSize) {
    int m = boardSize;
    int n = boardColSize[0];

    // First pass: apply transitions
    for (int row = 0; row < m; row++) {
        for (int col = 0; col < n; col++) {

            int liveNeighbors = countLiveNeighbors(board, m, n, row, col);

            if (board[row][col] == 1) {
                if (liveNeighbors < 2 || liveNeighbors > 3) {
                    board[row][col] = 2; // live -> dead
                }
            } else {
                if (liveNeighbors == 3) {
                    board[row][col] = 3; // dead -> live
                }
            }
        }
    }

    // Second pass: finalize states
    // mark encoded values with expected values .  
    for (int row = 0; row < m; row++) {
        for (int col = 0; col < n; col++) {
            if (board[row][col] == 2) board[row][col] = 0; // Replace 2 with 0(next state --> dead)
            else if (board[row][col] == 3) board[row][col] = 1; // Replace 3 with 1(next state --> live).
        }
    }
}

int main() {
    int m = 3, n = 3;

    // Allocate board
    int** board = (int**)malloc(m * sizeof(int*));
    for (int i = 0; i < m; i++) {
        board[i] = (int*)malloc(n * sizeof(int));
    }

    // Initialize board
    int temp[3][3] = {
        {0, 1, 0},
        {0, 1, 0},
        {0, 1, 0}
    };

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            board[i][j] = temp[i][j];
        }
    }

    int boardColSize[3] = {n, n, n};

    // Call function
    gameOfLife(board, m, boardColSize);

    // Print result
    printf("Updated Board:\n");
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }

    // Free memory
    for (int i = 0; i < m; i++) {
        free(board[i]);
    }
    free(board);

    return 0;
}
