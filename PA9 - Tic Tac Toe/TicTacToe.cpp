#include "TicTacToe.h"

using namespace std;

// constructor
TicTacToe::TicTacToe() {
    board = new char*[3];
    for (int i = 0; i < 3; i++) {
        board[i] = new char[3];
    }
    resetBoard();
}

// destructor
TicTacToe::~TicTacToe() {
    for (int i = 0; i < 3; i++) {
        delete [] board[i];
    }
    delete [] board;
}

// playGame() - main game loop
void TicTacToe::playGame() {
    bool gameover = false;
    bool continueGame = true;
    while (continueGame) {
        while (!gameover) {
            printBoard();
            playerMove();
            gameover = checkResult();
            if (gameover) {
                printf("Player wins!\n");
                break;
            }
            printBoard();
            computerMove();
            turn++;
            gameover = checkResult();
            if (gameover) {
                printf("Computer wins!\n");
                break;
            }
        }
        printf("Play again? (y/n): ");
        char input;
        cin >> input;
        if (input == 'y') {
            resetBoard();
            gameover = false;
        } else {
            continueGame = false;
        }
    }
}

// checkResult() - checks if the game is over
bool TicTacToe::checkResult() {
    // check rows
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != '~') {
            return true;
        }
    }
    // check columns
    for (int i = 0; i < 3; i++) {
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != '~') {
            return true;
        }
    }
    // check diagonals
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != '~') {
        return true;
    }
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != '~') {
        return true;
    }
    return false;
}

// printBoard() - prints the board
void TicTacToe::printBoard() {
    printf("\n");
    printf("%c  %c  %c\n", board[0][0], board[0][1], board[0][2]);
    printf("%c  %c  %c\n", board[1][0], board[1][1], board[1][2]);
    printf("%c  %c  %c\n", board[2][0], board[2][1], board[2][2]);
    printf("\n");
}

// resetBoard() - resets the board
void TicTacToe::resetBoard() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            board[i][j] = '~';
        }
    }
    turn = 0;
}

// playerMove() - gets player move
void TicTacToe::playerMove() {
    bool validRow = false;
    int row;
    while (!validRow) {
        printf("Enter row: \n");
        cin >> row;
        if (row >= 0 && row <= 2) {
            validRow = true;
            break;
        } else {
            printf("Invalid Selection\n");
            printf("Row can be 0, 1, or 2.\n");
        }
    }
    bool validCol = false;
    int col;
    while (!validCol) {
        printf("Enter col: \n");
        cin >> col;
        if (col >= 0 && col <= 2) {
            validCol = true;
            break;
        } else {
            printf("Invalid Selection\n");
            printf("Col can be 0, 1, or 2.\n");
        }
    }
    board[row][col] = 'X';
    lastPlayerMove = make_tuple(row, col);
}

// computerMove() - gets computer move
// make the computer annoyingly difficult to beat
// can use minmax algorithm to make it unbeatable
// this is a bitch to implement
/*
After the first player makes their move, take note of the position they chose.
On your first turn, choose a corner square that is not diagonal to the position 
chosen by the first player. This move will give you two possible ways to win the 
game: either by creating a diagonal line, or by creating a vertical and horizontal
line that intersect in the middle square.

If the first player responds by taking the center square, you should then take
a corner square that is diagonal to the position chosen by the first player. 
This will give you two more possible ways to win the game: either by creating 
a diagonal line or by creating a vertical and horizontal line that intersect 
in one of the corner squares.

If the first player responds by taking a corner square that is adjacent to 
their first move, you should take the remaining corner square that is diagonal
to their first move. This will give you two more possible ways to win the 
game: either by creating a diagonal line, or by creating a vertical and 
horizontal line that intersect in the middle square.

If the first player responds by taking a corner square that is not adjacent 
to their first move, you should take the center square. This will give you 
three possible ways to win the game: either by creating a diagonal line or 
by creating a vertical and horizontal line that intersect in the middle square.
*/
void TicTacToe::computerMove() {
    if (board[1][1] == '~') {
        board[1][1] = 'O';
        return;
    }
    else if (board[1][1] == 'X' && turn == 0) {
        // choose a random corner
        // [0][0], [0][2], [2][0], [2][2]
        int corner = rand() % 4;
        switch(corner) {
            case 0:
                board[0][0] = 'O';
                break;
            case 1:
                board[0][2] = 'O';
                break;
            case 2:
                board[2][0] = 'O';
                break;
            case 3:
                board[2][2] = 'O';
                break;
        }


    }
    // check to see if there is a spot that lets the computer win
    else if (turn >= 2) {
        checkComputerWin();
    }
    // block the player from winning; either symmetric or block 3 in a row
    else {
        checkComputerBlock();
    }
}

// checkComputerWin() - checks if the computer can win
void TicTacToe::checkComputerWin() {
    // check rows
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == board[i][1] && board[i][2] == '~' && board[i][0] == 'O') {
            board[i][2] = 'O';
            return;
        }
        if (board[i][0] == board[i][2] && board[i][1] == '~' && board[i][0] == 'O') {
            board[i][1] = 'O';
            return;
        }
        if (board[i][1] == board[i][2] && board[i][0] == '~' && board[i][1] == 'O') {
            board[i][0] = 'O';
            return;
        }
    }
    // check columns
    for (int i = 0; i < 3; i++) {
        if (board[0][i] == board[1][i] && board[2][i] == '~' && board[0][i] == 'O') {
            board[2][i] = 'O';
            return;
        }
        if (board[0][i] == board[2][i] && board[1][i] == '~' && board[0][i] == 'O') {
            board[1][i] = 'O';
            return;
        }
        if (board[1][i] == board[2][i] && board[0][i] == '~' && board[1][i] == 'O') {
            board[0][i] = 'O';
            return;
        }
    }
    // check diagonals
    if (board[0][0] == board[1][1] && board[2][2] == '~' && board[0][0] == 'O') {
        board[2][2] = 'O';
        return;
    }
    if (board[0][0] == board[2][2] && board[1][1] == '~' && board[0][0] == 'O') {
        board[1][1] = 'O';
        return;
    }
    if (board[1][1] == board[2][2] && board[0][0] == '~' && board[1][1] == 'O') {
        board[0][0] = 'O';
        return;
    }
}

// checkComputerBlock() - checks if the computer can block the player from winning
void TicTacToe::checkComputerBlock() {
    // check rows
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == board[i][1] && board[i][2] == '~' && board[i][0] == 'X') {
            board[i][2] = 'O';
            return;
        }
        if (board[i][0] == board[i][2] && board[i][1] == '~' && board[i][0] == 'X') {
            board[i][1] = 'O';
            return;
        }
        if (board[i][1] == board[i][2] && board[i][0] == '~' && board[i][1] == 'X') {
            board[i][0] = 'O';
            return;
        }
    }
    // check columns
    for (int i = 0; i < 3; i++) {
        if (board[0][i] == board[1][i] && board[2][i] == '~' && board[0][i] == 'X') {
            board[2][i] = 'O';
            return;
        }
        if (board[0][i] == board[2][i] && board[1][i] == '~' && board[0][i] == 'X') {
            board[1][i] = 'O';
            return;
        }
        if (board[1][i] == board[2][i] && board[0][i] == '~' && board[1][i] == 'X') {
            board[0][i] = 'O';
            return;
        }
    }
    // check diagonals
    if (board[0][0] == board[1][1] && board[2][2] == '~' && board[0][0] == 'X') {
        board[2][2] = 'O';
        return;
    }
    if (board[0][0] == board[2][2] && board[1][1] == '~' && board[0][0] == 'X') {
        board[1][1] = 'O';
        return;
    }
    if (board[1][1] == board[2][2] && board[0][0] == '~' && board[1][1] == 'X') {
        board[0][0] = 'O';
        return;
    }
    // else make a symmetric move to the player
    int row = get<0>(lastPlayerMove);
    int col = get<1>(lastPlayerMove);
    // if corner, choose opposite corner via modulo
    // need to check if the space is empty first
    if (row == 0 && col == 0) {
        board[2][2] = 'O';
        return;
    }
    if (row == 0 && col == 2) {
        board[2][0] = 'O';
        return;
    }
    if (row == 2 && col == 0) {
        board[0][2] = 'O';
        return;
    }
    if (row == 2 && col == 2) {
        board[0][0] = 'O';
        return;
    }
    // else choose opposite side via modulo
    if (row == 0 && col == 1) {
        board[2][1] = 'O';
        return;
    }
    if (row == 1 && col == 0) {
        board[1][2] = 'O';
        return;
    }
    if (row == 1 && col == 2) {
        board[1][0] = 'O';
        return;
    }
    if (row == 2 && col == 1) {
        board[0][1] = 'O';
        return;
    }
}
