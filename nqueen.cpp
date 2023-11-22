
#include <iostream>
#include <vector>

using namespace std;

bool isSafe(vector<vector<int>>& board, int row, int col, int n) {
    // Check if there is a Queen in the same column
    for (int i = 0; i < row; i++) {
        if (board[i][col] == 1) {
            return false;
        }
    }

    // Check upper-left diagonal
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j] == 1) {
            return false;
        }
    }

    // Check upper-right diagonal
    for (int i = row, j = col; i >= 0 && j < n; i--, j++) {
        if (board[i][j] == 1) {
            return false;
        }
    }

    return true;
}

bool solveNQueens(vector<vector<int>>& board, int row, int n) {
    if (row == n) {
        // All Queens are placed
        return true;
    }

    for (int col = 0; col < n; col++) {
        if (isSafe(board, row, col, n)) {
            board[row][col] = 1;

            if (solveNQueens(board, row + 1, n)) {
                return true;
            }

            // Backtrack
            board[row][col] = 0;
        }
    }

    return false;
}

void printBoard(vector<vector<int>>& board, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    int n;
    cout << "Enter the value of n for an n x n chessboard: ";
    cin >> n;

    // Initialize the board with zeros
    vector<vector<int>> board(n, vector<int>(n, 0));

    // Place the first Queen (you can choose any position)
    board[0][0] = 1;

    if (solveNQueens(board, 1, n)) {
        cout << "A valid placement of Queens:\n";
        printBoard(board, n);
    } else {
        cout << "No valid placement found.\n";
    }
return 0;
}