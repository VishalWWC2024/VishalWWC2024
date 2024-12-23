#include <iostream>
#include <limits>
using namespace std;

// Function to print the game board
void printBoard(char board[3][3]) {
    cout << "\n--------- Tic-Tac-Toe ---------\n";
    for (int i = 0; i < 3; i++) {
        cout << "| ";
        for (int j = 0; j < 3; j++) {
            cout << board[i][j] << " | ";
        }
        cout << "\n-------------------------------\n";
    }
}

// Function to check if a player has won
bool checkWin(char board[3][3], char player) {
    // Check rows, columns, and diagonals
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player) {
            return true; // row
        }
        if (board[0][i] == player && board[1][i] == player && board[2][i] == player) {
            return true; // column
        }
    }
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player) {
        return true; // diagonal
    }
    if (board[0][2] == player && board[1][1] == player && board[2][0] == player) {
        return true; // diagonal
    }
    return false;
}

// Function to check if the board is full (draw)
bool isBoardFull(char board[3][3]) {
    // Loop through the entire board to check if any cell is empty
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == ' ') {
                return false; // If an empty space is found, return false
            }
        }
    }
    return true; // If no empty space is found, return true (board is full)
}

// Function to clear the input buffer in case of invalid input
void clearInputBuffer() {
    cin.clear(); // clear error flags
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // discard invalid input
}

int main() {
    char playAgain;
    do {
        char board[3][3] = { { ' ', ' ', ' ' }, { ' ', ' ', ' ' }, { ' ', ' ', ' ' } };
        int row, col;
        char currentPlayer = 'X';

        cout << "Welcome to Tic-Tac-Toe!" << endl;
        cout << "Player 1: X, Player 2: O" << endl;
        cout << "The board positions are as follows:" << endl;
        cout << " 0 | 1 | 2 \n 3 | 4 | 5 \n 6 | 7 | 8\n" << endl;
        
        // Game loop
        while (true) {
            printBoard(board);
            cout << "Player " << currentPlayer << "'s turn." << endl;
            cout << "Enter row (0, 1, or 2): ";
            while (!(cin >> row) || row < 0 || row > 2) {
                clearInputBuffer();
                cout << "Invalid input! Please enter a valid row (0, 1, or 2): ";
            }
            cout << "Enter column (0, 1, or 2): ";
            while (!(cin >> col) || col < 0 || col > 2) {
                clearInputBuffer();
                cout << "Invalid input! Please enter a valid column (0, 1, or 2): ";
            }

            // Validate input
            if (board[row][col] != ' ') {
                cout << "This spot is already taken. Try again." << endl;
                continue;
            }

            // Place the current player's mark
            board[row][col] = currentPlayer;

            // Check for a win
            if (checkWin(board, currentPlayer)) {
                printBoard(board);
                cout << "Congratulations! Player " << currentPlayer << " wins!" << endl;
                break;
            }

            // Check for a draw
            if (isBoardFull(board)) {
                printBoard(board);
                cout << "It's a draw!" << endl;
                break;
            }

            // Switch to the other player
            currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
        }

        // Ask if the players want to play again
        cout << "Do you want to play again? (Y/N): ";
        cin >> playAgain;

        // Ensure valid input for replay
        while (playAgain != 'Y' && playAgain != 'N' && playAgain != 'y' && playAgain != 'n') {
            cout << "Invalid choice. Please enter Y to play again or N to quit: ";
            cin >> playAgain;
        }

    } while (playAgain == 'Y' || playAgain == 'y');

    cout << "Thank you for playing! Goodbye!" << endl;

    return 0;
}
