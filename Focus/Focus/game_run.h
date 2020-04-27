//
// Created by Lewis Zhang on 21/04/2020.
//

#ifndef FOCUS_GAME_RUN_H
#define FOCUS_GAME_RUN_H


#include "game_init.h"
#define BOARD_SIZE 8
#define PLAYERS_NUM 2

//player_flag
typedef struct player_flag{
    // turn status of the 1st player
    int flag_1;
    // turn status of the 2nd player
    int flag_2;
}player_flag;



//Function for player 1 move
void Player_1_Move( square board [BOARD_SIZE][BOARD_SIZE]);

piece * get_Ptr (square * s);
char get_Col (square * s);


#endif //FOCUS_GAME_RUN_H