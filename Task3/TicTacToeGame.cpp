#include <iostream>
using namespace std;

// Function prototypes
void displayBoard(char board[3][3]);
bool checkWin(char board[3][3], char player);
bool checkDraw(char board[3][3]);
void switchPlayer(char &currentPlayer);

int main() {
    // Internship Project: Tic-Tac-Toe (Row & Column Input)
    // Author: Shivanshu Tiwari
    // Date: Aug 2025

    char board[3][3] = { {' ', ' ', ' '},
                         {' ', ' ', ' '},
                         {' ', ' ', ' '} };

    char currentPlayer = 'X';
    int row, col;
    bool gameOver = false;
    char playAgain;

    cout << "--------------------------------------\n";
    cout << "         TIC-TAC-TOE GAME\n";
    cout << "--------------------------------------\n";
    cout << "Players will enter ROW and COLUMN numbers (1-3).\n";

    do {
        // Reset the board for new game
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++)
                board[i][j] = ' ';

        currentPlayer = 'X';
        gameOver = false;

        while (!gameOver) {
            displayBoard(board);

            // Player input
            cout << "Player " << currentPlayer << ", enter your move (row and column): ";
            cin >> row >> col;

            // Validate input
            if (row < 1 || row > 3 || col < 1 || col > 3) {
                cout << "Invalid position! Please enter values between 1 and 3.\n";
                continue;
            }
            if (board[row - 1][col - 1] != ' ') {
                cout << "Position already taken! Try another.\n";
                continue;
            }

            // Place player's mark
            board[row - 1][col - 1] = currentPlayer;

            // Check for win or draw
            if (checkWin(board, currentPlayer)) {
                displayBoard(board);
                cout << "🎉 Player " << currentPlayer << " wins!\n";
                gameOver = true;
            }
            else if (checkDraw(board)) {
                displayBoard(board);
                cout << "It's a draw!\n";
                gameOver = true;
            }
            else {
                switchPlayer(currentPlayer);
            }
        }

        cout << "Do you want to play again? (y/n): ";
        cin >> playAgain;

    } while (playAgain == 'y' || playAgain == 'Y');

    cout << "Thanks for playing Tic-Tac-Toe!\n";
    return 0;
}

// Function to display the current board
void displayBoard(char board[3][3]) {
    cout << "\n";
    for (int i = 0; i < 3; i++) {
        cout << " " << board[i][0] << " | " << board[i][1] << " | " << board[i][2] << "\n";
        if (i < 2) cout << "---|---|---\n";
    }
    cout << "\n";
}

// Check if the current player has won
bool checkWin(char board[3][3], char player) {
    // Rows and columns
    for (int i = 0; i < 3; i++) {
        if ((board[i][0] == player && board[i][1] == player && board[i][2] == player) ||
            (board[0][i] == player && board[1][i] == player && board[2][i] == player)) {
            return true;
        }
    }
    // Diagonals
    if ((board[0][0] == player && board[1][1] == player && board[2][2] == player) ||
        (board[0][2] == player && board[1][1] == player && board[2][0] == player)) {
        return true;
    }

    return false;
}

// Check if the game is a draw
bool checkDraw(char board[3][3]) {
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (board[i][j] == ' ')
                return false;
    return true;
}

// Switch current player
void switchPlayer(char &currentPlayer) {
    currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
}
