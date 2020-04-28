#include <stdio.h>
#include "input_output.h"

/* FUnction to print the board:
 * Invalid Squares are printed as | - |
 * Valid empty squares are printed as |   |
 * Valid squares with a GREEN piece are printed as | G |
 * Valid squares with a RED piece are printed as | R | */

void print_board(square board[BOARD_SIZE][BOARD_SIZE]){
    printf("****** The Board ******\n");
    printf("| 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 |C/R|\n");
    for(int i = 0; i < BOARD_SIZE; i ++){
        for (int j = 0; j < BOARD_SIZE; j++){
            if(board[i][j].type == VALID) {
                if(board[i][j].stack == NULL)
                    printf("|   ");
                else{
                    if (board[i][j].stack->p_color == GREEN)
                        printf("| G ");
                    else printf("| R ");
                }
            }
            else
                printf("| - ");
        }
        printf("| %d |\n",i+1);
    }
}

void num(square * s)
{
    printf("| %d ", s->num_pieces);
}

// Function for print the number_of_pieces.
void print_number_of_pieces(square board[BOARD_SIZE][BOARD_SIZE])
{
    printf("***** The number of pieces *****\n");

    printf("| 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 |C/R|\n");

    for (int i = 0; i < BOARD_SIZE; i++)
    {
        for (int j = 0; j < BOARD_SIZE; j++)
        {
            num(&board[i][j]);
        }
        printf("| %d |\n",i+1);
    }
}