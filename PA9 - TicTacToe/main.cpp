#include "TicTacToe.h"

int main() {
    TicTacToe *game = new TicTacToe();
    game->playGame();
    delete game;
    return 0;
}