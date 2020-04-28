//
// Created by Lili on 26/03/2020.
//
#include <stdio.h>
#include "input_output.h"
#include "game_run.h"

int main() {

    // declaration of the players and the board
    player players[PLAYERS_NUM];
    square board[BOARD_SIZE][BOARD_SIZE];
    int win_status=0;
    int tag=0;

    initialize_players(players);

    initialize_board(board);

    print_board(board);
    print_number_of_pieces(board);


    while(win_status==0)
    {

        tag = turn(players,tag);
        Player_1_Move(board);

        if( check_win(board)==1 && (players[0].own_kept==0 || players[1].own_kept==0))
        {// Red win
            win_status = 1;
        } else if ( check_win(board)==0 && (players[0].own_kept==0 || players[1].own_kept==0))
        {// Green win
            win_status = 2;
        }
    }

    if (win_status == 1)
    {// Red win
        print_board(board);
        printf("******** Result ********\n");
        printf("***     Red win!!    ***\n");
        printf("************************\n");
        //printf("The winner is %s , player_%d !",&players[]Players_name[],);
    }
    if (win_status == 2 )
    {// Green win
        print_board(board);
        printf("******** Result ********\n");
        printf("***    Green win!!   ***\n");
        printf("************************\n");

    }




    return 0;
}
