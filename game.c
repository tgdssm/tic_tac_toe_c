//
// Created by thali on 06/03/2023.
//

#include<stdio.h>
#include "game.h"

void initGame() {
    printf("   0   1   2 \n");
    printf("0    |   |   \n");
    printf("  ---+---+---\n");
    printf("1    |   |   \n");
    printf("  ---+---+---\n");
    printf("2    |   |   \n");
    struct Game game = {{0}, 1, 0};
    gameLoop(&game);
}

void showBoard(struct Game *game){
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            if (j == 2)
            {
                if (game->board[i][j] == 1) printf(" X ");
                else if (game->board[i][j] == -1)  printf(" O ");
                else printf("   ");
            }
            else
            {
                if (game->board[i][j] == 1) printf(" X |");
                else if (game->board[i][j] == -1) printf(" O |");
                else printf("   |");
            }
        }
        if (i < 2)
        {
            printf("\n---+---+---");
        }
        printf("\n");
    }
}

void makePlay(struct Game *game) {
    int positionX, positionY;
    scanf("%d", &positionX);
    scanf("%d", &positionY);
    if(positionX >= 0 && positionX <= 2 && positionY >= 0 && positionY <= 2){
        if(game->currentPlayer == 1 && game->board[positionX][positionY] != 1 && game->board[positionX][positionY] != -1) {
            game->board[positionX][positionY] = 1;
            game->currentPlayer = 2;
        } else if(game->currentPlayer == 2 && game->board[positionX][positionY] != 1 && game->board[positionX][positionY] != -1) {
            game->board[positionX][positionY] = -1;
            game->currentPlayer = 1;
        } else {
            printf("Jogada inválida, tente novamente.\n");
            makePlay(game);
        }
    } else {
        printf("Jogada inválida, tente novamente.\n");
        makePlay(game);
    }
}

int checkGame(struct Game *game){
    int vertical, horizontal, diagonal, tiedGame = 0;
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            horizontal = game->board[i][0] + game->board[i][1] + game->board[i][2];
            if(horizontal == 3 || horizontal == -3) return  horizontal;

            vertical = game->board[0][j] + game->board[1][j] + game->board[2][j];
            if(vertical == 3 || vertical == -3) return  vertical;

            diagonal = game->board[0][0] + game->board[1][1] + game->board[2][2];
            if(diagonal == 3 || diagonal == -3) return  diagonal;
            diagonal = game->board[0][2] + game->board[1][1] + game->board[2][0];
            if(diagonal == 3 || diagonal == -3) return  diagonal;

            if(game->board[i][j] != 0) {
                tiedGame++;
                if(tiedGame == 9) {
                    return 1;
                }
            }
        }
    }
    return 0;
}

void gameLoop(struct Game *game) {
    while(game->points != 3 && game->points != -3 && game->points != 9){
        makePlay(game);
        showBoard(game);
        game->points = checkGame(game);
    }
    resultGame(game);
}

void resultGame(struct Game *game) {
    if(game->points == 3)
        printf("Player 1 ganhou!!!");
    else if(game->points == -3)
        printf("Player 2 ganhou!!!");
    else
        printf("Empate");
    char newGame;
    printf("Deseja jogar novamente? s/n");
    scanf("%c", &newGame);
    if (newGame == 's') initGame();
    else return;
}




