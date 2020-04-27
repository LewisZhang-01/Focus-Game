//
// Created by Lewis Zhang on 21/04/2020.
//
#include <stdio.h>
#include <stdlib.h>
#include "game_run.h"
#include "input_output.h"


player_flag flags;




int *nextPtr = NULL;
piece *top = NULL;
piece *curr = NULL;


void turn(player players[PLAYERS_NUM])
{
    if(players[0].player_color == RED)
    {
        printf("Now it's %s's turn (Red side)!\n",&players[0].Players_name[0]);// Output players' turn.

    } else
    {
        printf("Now it's %s's turn (Red side)!\n",&players[1].Players_name[1]);// Output players' turn.
    }
}

// Player 1 move
void Player_1_Move(square board [BOARD_SIZE][BOARD_SIZE])
{
    int x = 0;
    int y = 0;
    int dx = 0;
    int dy = 0;

    //while (flags.flag_1==1)
    //{
        printf("Please enter coordinates row:\n");
        scanf("%d", &x);
        printf("Please enter coordinates column:\n");
        scanf("%d", &y);
        printf("Please enter destination coordinates row:\n");
        scanf("%d", &dx);
        printf("Please enter destination coordinates column:\n");
        scanf("%d", &dy);
        if (x >= 1 && x <= BOARD_SIZE && y >= 1 && y <= BOARD_SIZE && dx >= 1 && dx <= BOARD_SIZE && dy >= 1 && dy <= BOARD_SIZE)
        {// Coordinate correct

            top = get_Ptr(&board[dx][dy]);
            push(&board[x][y] ,top);

            char color = get_Col(&board[x][y]);

            print_board(board);
            print_number_of_pieces(board);

            printf("Stack Data: %u\n", board[dx][dy].stack->p_color);
        }
        else
        {
            printf("Error! This coordinates is invalid!\n");
            printf("Please enter again:\n");

        }
    //}
}
void push(square * s, piece *top)
{
    piece * current = top;
    top = malloc(sizeof(piece));
    top->p_color = get_Col(s);
    top->next = current;
    s->num_pieces --;

}

piece * get_Ptr (square * s)
{
    s->num_pieces ++;
    return s->stack;
}
char get_Col (square * s)
{
    return s->stack->p_color;
}