//
// Created by thali on 06/03/2023.
//

#ifndef TIC_TAC_TOE_GAME_H
#define TIC_TAC_TOE_GAME_H

#endif //TIC_TAC_TOE_GAME_H

struct Game {
    int board[3][3];
    int currentPlayer;
    int points;
};

void initGame();
void showBoard(struct Game *game);
void makePlay(struct Game *game);
void gameLoop(struct Game *game);
int checkGame(struct Game *game);
void resultGame(struct Game *game);