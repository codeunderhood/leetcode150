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

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
// directions --> 8 directions. directions[0] --> first direction, direction[7] --> 8th direction
// directions[1] --> {-1,0}
// directions[1][0] = {-1} , directions[1][1] = {0} 
    vector<vector<int>> directions = {
        {-1, -1}, {-1, 0}, {-1, 1},
        {0, -1},           {0, 1},
        {1, -1},  {1, 0},  {1, 1}
    };

    int countLiveNeighbors(vector<vector<int>>& board, int m, int n, int row, int col) {
        int count = 0;

        for (int d = 0; d < 8; d++) {
            int newRow = row + directions[d][0];  // Example : d = 1 --> directions[1][0] = {-1}
            int newCol = col + directions[d][1]; // Example : d = 1 --> directions[1][1] = {0} 

            if (newRow >= 0 && newRow < m && newCol >= 0 && newCol < n) {
                // original live cells: 1 and 2
                if (board[newRow][newCol] == 1 || board[newRow][newCol] == 2) {
                    count++;  // 1,2 --> originally live
                }
            }
        }

        return count;
    }

    void gameOfLife(vector<vector<int>>& board) {
        int m = board.size();
        int n = board[0].size();

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
          // mark encoded values with expected values 
        for (int row = 0; row < m; row++) {
            for (int col = 0; col < n; col++) {
                if (board[row][col] == 2) board[row][col] = 0; // Replace 2 with 0(next state --> dead)
                else if (board[row][col] == 3) board[row][col] = 1; // Replace 3 with 1(next state --> live)
            }
        }
    }
};


int main() {
    Solution sol;

    vector<vector<int>> board = {
        {0, 1, 0},
        {0, 1, 0},
        {0, 1, 0}
    };

    cout << "Original Board:\n";
    for (auto &row : board) {
        for (int val : row) cout << val << " ";
        cout << "\n";
    }

    sol.gameOfLife(board);

    cout << "\nUpdated Board:\n";
    for (auto &row : board) {
        for (int val : row) cout << val << " ";
        cout << "\n";
    }

    return 0;
}
