//
// Created by Lili on 24/03/2020.
//

#ifndef FOCUS_GAME_INIT_H
#define FOCUS_GAME_INIT_H



#define BOARD_SIZE 8
#define PLAYERS_NUM 2

//colors that a piece can have
typedef enum color {
    RED,
    GREEN
}color;

// Square types
//INVALID: squares that are on the sides and where no piece can be placed
//VALID: squares where it is possible to place a piece or a stack
typedef enum square_type{
    VALID,
    INVALID
}square_type;

//Player
typedef struct player{
    //the color associated with the player
    color player_color;
    //the name associated with the player
    char Players_name[20];
    //the number of own pieces kept associated with the player
    int own_kept;
    //the number of adversary's pieces captured associated with the player
    int adv_captured;
}player;


// A piece
typedef struct piece {
    //the color associated with a piece
    color p_color;

    // This is a pointer to the next pieces to create a stack.
    struct piece * next;

}piece;



// A Square of the board
typedef struct square{
    // type of the square (VALID/INVALID)
    square_type type;

    //the piece or the top piece on the stack
    piece * stack;

    //number of pieces on the square
    int num_pieces;

}square;

//Function to create the players
void initialize_players(player players[PLAYERS_NUM]);

//Function to create the board
void initialize_board(square board[BOARD_SIZE][BOARD_SIZE]);




//Function to manage player's turn
int turn(player players[PLAYERS_NUM],int tag);


piece * push(square * s, piece *top);
piece * push_with_stack(square * s, piece *top, int num);


#endif //FOCUS_GAME_INIT_H


