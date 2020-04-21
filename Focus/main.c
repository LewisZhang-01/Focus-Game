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


    initialize_players(players);

    initialize_board(board);

    print_board(board);
    print_number_of_pieces(board);

    turn();
    return 0;
}
