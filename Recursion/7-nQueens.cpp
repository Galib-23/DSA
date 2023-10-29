/*
    Conditions to check for safe places:
        if(c1 =! c2 and r1 != r2 and (abs(c1 - c2) != abs(r1 - r2)))
*/
#include <iostream>
#include <vector>
using namespace std;
bool isSafe(vector<vector<int>>& board, int row, int col, int N) {
    // Check the column on the left
    for (int i = 0; i < col; i++) {
        if (board[row][i] == 1) {
            return false;
        }
    }

    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j] == 1) {
            return false;
        }
    }

    // Check the lower-left diagonal
    for (int i = row, j = col; i < N && j >= 0; i++, j--) {
        if (board[i][j] == 1) {
            return false;
        }
    }

    return true;
}

bool solveNQueensUtil(vector<vector<int>>& board, int col, int N) {
    // Base case: If all queens are placed, return true
    if (col == N) {
        return true;
    }

    for (int row = 0; row < N; row++) {
        if (isSafe(board, row, col, N)) {
            board[row][col] = 1;

            // Recursively solve for the next column
            if (solveNQueensUtil(board, col + 1, N)) {
                return true;
            }

            // If placing a queen in board[row][col] doesn't lead to a solution,
            // then remove the queen (backtrack)
            board[row][col] = 0;
        }
    }

    // If no safe position was found for this column, return false
    return false;
}

bool solveNQueens(int N) {
    vector<vector<int>> board(N, vector<int>(N, 0));

    if (solveNQueensUtil(board, 0, N)) {
        // Print the board with queens placed
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                cout << (board[i][j] ? "Q" : ".") << " ";
            }
            cout << endl;
        }
        return true;
    }

    // If no solution exists, return false
    return false;
}

int main() {
    int N;
    cout << "Enter the value of N: ";
    cin >> N;

    if (solveNQueens(N)) {
        cout << "Solution found!" << endl;
    } else {
        cout << "No solution exists." << endl;
    }

    return 0;
}

