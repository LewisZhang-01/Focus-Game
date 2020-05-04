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
    printf("*************************************\n");
    printf("***        Focus Board Game       ***\n");
    printf("*************************************\n");
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
    printf("\n");// New line.
    print_number_of_pieces(board);
    printf("\n");// New line.

    // While loop, until the winner is decided.
    while(win_status==0)
    {
        // The conditions for check if player can use own kept pieces.
        if ( check_win(board)==1 ) // red will win, let green go with own kept piece.
        {
            tag = turn(players,tag);
            move_own_kept(board,1);
        } else if ( check_win(board)==0 ) // green will win, let red go with own kept piece.
        {
            tag = turn(players,tag);
            move_own_kept(board,0);
        }

        tag = turn(players,tag);// Call return function and return an integer value to show who is current player.
        win_status = Player_Move(board,tag);// Player start move.
    }

    // Print the winner's info.
    if (win_status == 1)
    {// Red win
        print_board(board);
        printf("************** Result ***************\n");
        printf("***           Red win!!           ***\n");
        printf("*************************************\n");
    }
    if (win_status == 2 )
    {// Green win
        print_board(board);
        printf("************** Result ***************\n");
        printf("***          Green win!!          ***\n");
        printf("*************************************\n");
    }

    return 0;
}
