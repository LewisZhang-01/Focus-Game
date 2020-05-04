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

//Function for player move
int Player_Move( square board [BOARD_SIZE][BOARD_SIZE], int tag);

//Function for detail of move
int move( square board [BOARD_SIZE][BOARD_SIZE],square * s,int x, int y, int dx, int dy);

//Function for update player's own pieces kept & adversary's pieces captured status.
void update(int n, int player_num,int opponent_num);

//Function for get target memory address.
piece * get_Ptr (square * s);
piece * get_Ptr_stack (square * s,int num_1, int num_2);

//Function for get the color of the target coordinates.
char get_Col (square * s);

//Function for delete previous coordinates.
void delete (square * s);

//Function for check if there are any winner generate.
int check_win (square board [BOARD_SIZE][BOARD_SIZE]);

// Move kept piece.
void move_own_kept (square board [BOARD_SIZE][BOARD_SIZE],int color);

// Update player's own kept and captured pieces.
void print_kept_and_capt (int player__color);

#endif //FOCUS_GAME_RUN_H