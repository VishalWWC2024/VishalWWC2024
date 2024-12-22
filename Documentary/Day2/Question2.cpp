#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

bool isValidSudoku(const vector<vector<char>>& board) {
    // Use sets to track seen numbers for rows, columns, and boxes
    unordered_set<char> rows[9], cols[9], boxes[9];

    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            char num = board[i][j];
            if (num != '.') { // Only check filled cells
                // Calculate the index for the 3x3 box
                int boxIndex = (i / 3) * 3 + (j / 3);

                // Check for duplicates in the row, column, and box
                if (rows[i].count(num) || cols[j].count(num) || boxes[boxIndex].count(num)) {
                    return false; // Found a duplicate
                }

                // Add the number to the respective sets
                rows[i].insert(num);
                cols[j].insert(num);
                boxes[boxIndex].insert(num);
            }
        }
    }

    return true; // No duplicates found, the board is valid
}

int main() {
    // Example Sudoku board (valid)
    vector<vector<char>> board = {
        {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
        {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
        {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
        {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
        {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
        {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
        {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
        {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
        {'.', '.', '.', '.', '8', '.', '.', '7', '9'}
    };

    if (isValidSudoku(board)) {
        cout << "The Sudoku board is valid." << endl;
    } else {
        cout << "The Sudoku board is not valid." << endl;
    }

    return 0;
}