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
#include <stdlib.h>

int directions[8][2] = {
    {-1, -1}, {-1, 0}, {-1, 1},
    {0, -1},           {0, 1},
    {1, -1},  {1, 0},  {1, 1}
};

int countLiveNeighbors(int** board, int m, int n, int row, int col) {
    int count = 0;

    for (int d = 0; d < 8; d++) {
        int newRow = row + directions[d][0];
        int newCol = col + directions[d][1];

        if (newRow >= 0 && newRow < m && newCol >= 0 && newCol < n) {
            // original live cells: 1 and 2
            if (board[newRow][newCol] == 1 || board[newRow][newCol] == 2) {
                count++;
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
    for (int row = 0; row < m; row++) {
        for (int col = 0; col < n; col++) {
            if (board[row][col] == 2) board[row][col] = 0;
            else if (board[row][col] == 3) board[row][col] = 1;
        }
    }
}
