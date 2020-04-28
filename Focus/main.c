//
//  Student Name: Zhi Zhang
//  Student Number: 18210054
//
//  COMP10050 Software Engineering Project 1
//  Assignment 2 – Focus/Domination Board Game
//
#include <stdio.h>
#include "input_output.h"
#include "game_run.h"

int main()
{
    // Declaration of the players and the board.
    player players[PLAYERS_NUM];
    square board[BOARD_SIZE][BOARD_SIZE];
    // Declaration of some variable.
    int win_status=0;
    int tag=0;

    // Call functions.
    initialize_players(players);
    initialize_board(board);
    print_board(board);
    print_number_of_pieces(board);

    // While loop, until the winner is decided.
    while(win_status==0)
    {
        tag = turn(players,tag);// Call return function and return an integer value to show who is current player.
        Player_Move(board,tag);// Player start move.

        // The conditions for judging the winner.
        //The game is won when the opponent's pieces on the board cannot move and the number of out-of-court moves is 0.
        if( check_win(board)==1 && (players[0].own_kept==0 || players[1].own_kept==0))
        {// Red win.
            win_status = 1; // assign new value to jump out from the loop.
        } else if ( check_win(board)==0 && (players[0].own_kept==0 || players[1].own_kept==0))
        {// Green win.
            win_status = 2;
        }
    }

    // Print the winner's info.
    if (win_status == 1)
    {// Red win
        print_board(board);
        printf("******** Result ********\n");
        printf("***     Red win!!    ***\n");
        printf("************************\n");
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
