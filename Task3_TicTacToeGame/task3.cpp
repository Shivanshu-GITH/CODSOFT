#include <iostream>
using namespace std;

char board[3][3];
char currentPlayer = 'X';

// Initialize board with empty spaces
void initializeBoard() {
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            board[i][j] = ' ';
}

// Display board nicely
void displayBoard() {
    cout << "\n";
    cout << "   1   2   3\n";
    for (int i = 0; i < 3; i++) {
        cout << i + 1 << "  ";
        for (int j = 0; j < 3; j++) {
            cout << board[i][j];
            if (j < 2) cout << " | ";
        }
        cout << "\n";
        if (i < 2) cout << "  ---|---|---\n";
    }
    cout << "\n";
}

// Switch current player
void switchPlayer() {
    currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
}

// Player makes a move
bool makeMove(int row, int col) {
    if (row >= 1 && row <= 3 && col >= 1 && col <= 3 && board[row - 1][col - 1] == ' ') {
        board[row - 1][col - 1] = currentPlayer;
        return true;
    }
    return false;
}

// Check win condition
bool checkWin() {
    for (int i = 0; i < 3; i++) {
        // Rows and columns
        if ((board[i][0] == currentPlayer && board[i][1] == currentPlayer && board[i][2] == currentPlayer) ||
            (board[0][i] == currentPlayer && board[1][i] == currentPlayer && board[2][i] == currentPlayer))
            return true;
    }
    // Diagonals
    if ((board[0][0] == currentPlayer && board[1][1] == currentPlayer && board[2][2] == currentPlayer) ||
        (board[0][2] == currentPlayer && board[1][1] == currentPlayer && board[2][0] == currentPlayer))
        return true;

    return false;
}

// Check draw
bool checkDraw() {
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (board[i][j] == ' ')
                return false;
    return true;
}

int main() {
    char playAgain;

    do {
        initializeBoard();
        currentPlayer = 'X';
        bool gameOver = false;

        while (!gameOver) {
            displayBoard();
            int row, col;
            cout << "Player " << currentPlayer << ", enter your move (row and column: 1 2): ";
            cin >> row >> col;

            if (!makeMove(row, col)) {
                cout << "Invalid move! Try again.\n";
                continue;
            }

            if (checkWin()) {
                displayBoard();
                cout << "Player " << currentPlayer << " wins!\n";
                gameOver = true;
            } else if (checkDraw()) {
                displayBoard();
                cout << "It's a draw!\n";
                gameOver = true;
            } else {
                switchPlayer();
            }
        }

        cout << "Do you want to play again? (y/n): ";
        cin >> playAgain;
    } while (playAgain == 'y' || playAgain == 'Y');

    return 0;
}
// End of the Tic Tac Toe Game program