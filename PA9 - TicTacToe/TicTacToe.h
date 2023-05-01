#ifndef TICTACTOE_H
#define TICTACTOE_H

#include <iostream>
#include <string>
#include <stdlib.h>
#include <stdio.h>
#include <tuple>

using namespace std;

class TicTacToe {
public:
    TicTacToe();
    ~TicTacToe();
    void playGame();

private:
    char **board;
    int turn;

    tuple<int, int> lastPlayerMove;

    bool checkResult();
    void printBoard();
    void resetBoard();
    void playerMove();
    void computerMove();
    void checkComputerWin();
    void checkComputerBlock();

};

#endif