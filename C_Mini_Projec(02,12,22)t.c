#include <stdio.h>
// Function to initialize the Tic-Tac-Toe board
void initializeBoard(char board[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            board[i][j] = ' ';
        }
    }
}

// Function to display the Tic-Tac-Toe board
void displayBoard(char board[3][3]) {
     printf(" %c | %c | %c\n", board[0][0], board[0][1], board[0][2]);
    printf("---|---|---\n");
    printf(" %c | %c | %c\n", board[1][0], board[1][1], board[1][2]);
    printf("---|---|---\n");
    printf(" %c | %c | %c\n", board[2][0], board[2][1], board[2][2]);
}

// Function to check if the game has a winner
int checkWin(char board[3][3], char player) {
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player) {
            return 1; // Rows
        }
        if (board[0][i] == player && board[1][i] == player && board[2][i] == player) {
            return 1; // Columns
        }
    }
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player) {
        return 1; // Diagonal (top-left to bottom-right)
    }
    if (board[0][2] == player && board[1][1] == player && board[2][0] == player) {
        return 1; // Diagonal (top-right to bottom-left)
    }
    return 0;
}

// Function to check if the board is full (a draw)
int checkDraw(char board[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == ' ') {
                return 0; // There are empty spaces, so the game is not a draw
            }
        }
    }
    return 1; // The board is full, and the game is a draw
}

int main() {
    char board[3][3];
    int row, col;
    char currentPlayer = 'X';

    initializeBoard(board);

    printf("Welcome to Tic-Tac-Toe!\n");

    while (1) {
        displayBoard(board);
        printf("Player %c, enter your move (row and column): ", currentPlayer);
        scanf("%d %d", &row, &col);

        // Check if the move is valid
        if (row < 1 || row > 3 || col < 1 || col > 3 || board[row - 1][col - 1] != ' ') {
            printf("Invalid move. Try again.\n");
            continue;
        }

        board[row - 1][col - 1] = currentPlayer;

        // Check for a win
        if (checkWin(board, currentPlayer)) {
            displayBoard(board);
            printf("Player %c wins! Congratulations!\n", currentPlayer);
            break;
        }

        // Check for a draw
        if (checkDraw(board)) {
            displayBoard(board);
            printf("It's a draw! Good game!\n");
            break;
        }

        // Switch to the other player
        if (currentPlayer == 'X') {
            currentPlayer = 'O';
        } else {
            currentPlayer = 'X';
        }
    } return 0;
}
