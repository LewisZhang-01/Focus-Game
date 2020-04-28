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
    int flag_0;
    // turn status of the 2nd player
    int flag_1;
}player_flag;



//Function for player 1 move
void Player_1_Move( square board [BOARD_SIZE][BOARD_SIZE]);
int move( square board [BOARD_SIZE][BOARD_SIZE],square * s,int x, int y, int dx, int dy);
void update(player Players[PLAYERS_NUM],int n, int player_num,int opponent_num);
piece * get_Ptr (square * s);
piece * get_Ptr_stack (square * s,int num_1, int num_2);
char get_Col (square * s);

void delete (square * s, piece *temp);
void delete_more (square * s, int num);

int check_win (square board [BOARD_SIZE][BOARD_SIZE]);

#endif //FOCUS_GAME_RUN_H