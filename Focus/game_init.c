#include <stdio.h>
#include <stdlib.h>
#include "game_init.h"
#include "game_run.h"

// Function to initialize the players.
void initialize_players(player players[PLAYERS_NUM])
{
    // implement here the functionality to initialize the players
    int player_color_choice[PLAYERS_NUM];

    for(int i=0; i<PLAYERS_NUM;i++)
    {// Ask user input players' name.
        printf("-------------------------------------\n");
        printf("Please enter the N0.%d Player's name:\n",i+1);
        scanf("%s",&players[i].Players_name[i]);
        printf("-------------------------------------\n");
        if (i==1)// Check if it runs for player_2.
        {
            if (player_color_choice[i-1]==0)// If player_1 chooses red color, the second player can only choose green.
            {
                printf("*Red occupied by player_1, \nautomatically assign to Green color.\n");
                player_color_choice[i] = 1;
            }
            else
            {// If player_1 chooses green color, the second player can only choose red.
                printf("*Green occupied by player_1, \nautomatically assign to Red color.\n");
                player_color_choice[i] = 0;
            }
        }
        else
        {// 1st round.
            printf("Please choose a color:\n0.Red\n1.Green\n");
            scanf("%d",&player_color_choice[i]);
        }
        // start with 0 in both player own kept & adv_captured pieces.
        players[i].own_kept = 0;
        players[i].adv_captured = 0;
    }

    for(int i=0; i<PLAYERS_NUM;i++)
    {
        printf("-------------------------------------\n");
        printf("NO.%d Player's name: %s\n", i+1, &players[i].Players_name[i]);// Output players' name.
        if(player_color_choice[i]==0)
        {// If user choose 0 that means Red.
            players[i].player_color = RED;
        }
        if(player_color_choice[i]==1)
        {// If user choose 1 that means Green.
            players[i].player_color = GREEN;
        }
        switch(players[i].player_color)
        {// Print user choice.
            case (RED):// if player choose red then print red.
                printf("NO.%d Player's color: %s \n", i + 1, "Red");
                break;
            case (GREEN):// if player choose green then print green.
                printf("NO.%d Player's color: %s \n", i + 1, "Green");
                break;
            default:
                break;
        }
        // Print number of own pieces accumulated and number of adversary’s pieces captured.
        printf("The number of own pieces NO.%d player \naccumulated: %d\n",i+1,players[i].own_kept);
        printf("The number of adversary’s pieces NO.%d \nplayer captured: %d\n",i+1,players[i].adv_captured);
        printf("-------------------------------------\n");
    }
    printf("\n");// New line.
}

//Set Invalid Squares (where it is not possible to place stacks)
void set_invalid(square * s)
{
    s->type = INVALID;
    s->stack = NULL;
    s->num_pieces = 0;
}

//Set Empty Squares (with no pieces/stacks)
void set_empty(square * s)
{
    s->type = VALID;
    s->stack = NULL;
    s->num_pieces = 0;
}

//Set squares with a GREEN piece
void set_green(square * s)
{
    s->type = VALID;
    s->stack = (piece *) malloc (sizeof(piece));
    s->stack->p_color = GREEN;
    s->stack->next = NULL;
    s->num_pieces = 1;
}

//Set squares with a RED piece
void set_red(square * s)
{
    s->type = VALID;
    s->stack = (piece *) malloc (sizeof(piece));
    s->stack->p_color = RED;
    s->stack->next = NULL;
    s->num_pieces = 1;
}

//initializes the board
void initialize_board(square board [BOARD_SIZE][BOARD_SIZE])
{
    for(int i=0; i< BOARD_SIZE; i++)
    {
        for(int j=0; j< BOARD_SIZE; j++)
        {
            //invalid squares
            if((i==0 && (j==0 || j==1 || j==6 || j==7)) || (i==1 && (j==0 || j==7)) || (i==6 && (j==0 || j==7)) || (i==7 && (j==0 || j==1 || j==6 || j==7)))
            {
                set_invalid(&board[i][j]);
            }
            else
            {//squares with no pieces
                if(i==0 || i ==7 || j==0 || j == 7)
                {
                    set_empty(&board[i][j]);
                }
                else
                {//squares with red pieces
                    if((i%2 == 1 && (j < 3 || j> 4)) || (i%2 == 0 && (j == 3 || j==4)))
                    {
                        set_red(&board[i][j]);
                    }
                    else
                    {//green squares
                        set_green(&board[i][j]);
                    }
                }
            }
        }
    }
}