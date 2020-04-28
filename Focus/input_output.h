#ifndef FOCUS_INPUT_OUTPUT_H
#define FOCUS_INPUT_OUTPUT_H

#include "game_init.h"

//Function to print the board
void print_board(square board[BOARD_SIZE][BOARD_SIZE]);

//Function to print the number of pieces on board
void print_number_of_pieces(square board[BOARD_SIZE][BOARD_SIZE]);

//Function to call the count struct
void num(square * s);

#endif //FOCUS_INPUT_OUTPUT_H