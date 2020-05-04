#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "game_run.h"
#include "input_output.h"
#include "game_init.h"

// Declare some structures, variables, etc...
player_flag flags;
player Players[PLAYERS_NUM];
int first=0;
int player_color;

// The function that performs turn control.
int turn(player players[PLAYERS_NUM],int tag)
{
    if (first == 0)// if it is the first round.
    {// Assign again the name of each players.
        strcpy(&Players[0].Players_name[0],&players[0].Players_name[0]);
        strcpy(&Players[1].Players_name[1],&players[1].Players_name[1]);

        // If 1st player choose red.
        if (players[0].player_color == RED) {
            // Output players' turn.
            switch (players[0].player_color) {// Print user choice.
                case (RED):// if player choose red then print red.
                    printf("Now it's %s's turn (%s side)!\nYou can only choose Red color piece.\n", &players[0].Players_name[0], "Red");
                    break;
                case (GREEN):// if player choose green then print green.
                    printf("Now it's %s's turn (%s side)!\nYou can only choose Green color piece.\n", &players[0].Players_name[0], "Green");
                    break;
                default:
                    break;
            }
            flags.flag_0 = 0;// red
            flags.flag_1 = 1;// green
            first++; // update.
            return 1;
        } else if (players[1].player_color == RED) {// If 2nd player choose red.
            switch (players[1].player_color) {// Print user choice.
                case (RED):// if player choose red then print red.
                    printf("Now it's %s's turn (%s side)!\nYou can only choose Red color piece.\n", &players[1].Players_name[1], "Red");
                    break;
                case (GREEN):// if player choose green then print green.
                    printf("Now it's %s's turn (%s side)!\nYou can only choose Green color piece.\n", &players[1].Players_name[1], "Green");
                    break;
                default:
                    break;
            }// Output players' turn.
            flags.flag_1 = 0;// red
            flags.flag_0 = 1;// green
            first++;// update.
            return 0;
        }
    }
    // For rest of rounds.
    if (tag == 0) {
        switch (players[0].player_color) {// Print user choice.
            case (RED):// if player choose red then print red.
                printf("Now it's %s's turn (%s side)!\nYou can only choose Red color piece.\n", &players[0].Players_name[0], "Red");
                break;
            case (GREEN):// if player choose green then print green.
                printf("Now it's %s's turn (%s side)!\nYou can only choose Green color piece.\n", &players[0].Players_name[0], "Green");
                break;
            default:
                break;
        }
        return 1;
    } else if (tag == 1)
    {
        switch (players[1].player_color) {// Print user choice.
            case (RED):// if player choose red then print red.
                printf("Now it's %s's turn (%s side)!\nYou can only choose Red color piece.\n", &players[1].Players_name[1], "Red");
                break;
            case (GREEN):// if player choose green then print green.
                printf("Now it's %s's turn (%s side)!\nYou can only choose Green color piece.\n", &players[1].Players_name[1], "Green");
                break;
            default:
                break;
        }
        return 0;
    }
    return 0;
}

// Function for Player move
int Player_Move(square board [BOARD_SIZE][BOARD_SIZE], int tag)
{
    int x = 0;
    int y = 0;
    int dx = 0;
    int dy = 0;
    int choice = 0;
    int pass = 0;

    // some condition for player's choice.
    while(pass==0)
    {
        printf("Please enter the corresponding abscissa \nof the piece/stack you want to move:\n");
        printf("(Column number)\n");
        scanf("%d", &y);
        printf("Please enter the corresponding ordinate \nof the piece/stack you want to move:\n");
        printf("(Row number)\n");
        scanf("%d", &x);
        // 1-8 on the command line board and 0-7 here, convert.
        x-=1;
        y-=1;

        // The game does not allow a stack or piece to be moved outside the size of the board and in the angle squares that cannot contain any piece or stack.
        if (((x == 0 && (y<=1 || y>=6))||(x == 1 && (y<0 || y>7))||(x == 6 && (y<0 || y>7))||(x == 7 && (y<=1 || y>=6))) || x<0 || x > BOARD_SIZE || y < 0 || y > BOARD_SIZE || dx < 0 || dx > BOARD_SIZE || dy < 0 || dy > BOARD_SIZE)
        {
            printf("Error! This coordinates is invalid!\n");
            printf("Please replace it with another one:\n");
            pass = 0;

        } else if ((board[x][y].stack->p_color==GREEN && tag==1)||(board[x][y].stack->p_color==RED && tag==0)) // current choose : red but player1:green
        {// The game allows a player to move his own pieces or only a stack that has a top piece of the same colour of the player.
            printf("Error! You can only choose the color \nas same as you are!\n");
            printf("Please replace it with another one:\n");
            pass = 0;

        }
        else// otherwise pass.
        {
            pass = 1;
        }
    }

    // Check the winner.
    //The game is won when the opponent's pieces on the board cannot move and the number of own kept piece is 0.
    if( check_win(board)==1 && (Players[0].own_kept==0 || Players[1].own_kept==0))
    {// Red win.
        return 1;
    } else if ( check_win(board)==0 && (Players[0].own_kept==0 || Players[1].own_kept==0))
    {// Green win.
        return 2;
    }

    // The game allows to move a piece/stack of a number of positions (up, down,left or right) corresponding to the size of the stack.
    int num =board[x][y].num_pieces;
    printf("The total number in your choose stack \nis %d, so you can move %d step(s).\n ",num,num);
    for (int i = 0; i < num; ++i)
    {// Ask player to enter the direction of movement.
        printf("Now:%d/%d\nIf you want:\n1.Up\n2.Down\n3.Left\n4.Right\n",i+1,num);
        scanf("%d",&choice);
        switch (choice)
        {
            case 1:// Up
                dx=x-1;
                dy=y;
                move(board,&board[dx][dy],x,y,dx,dy);
                x=dx;
                y=dy;
                break;
            case 2:// Down
                dx=x+1;
                dy=y;
                move(board,&board[dx][dy],x,y,dx,dy);
                x=dx;
                y=dy;
                break;
            case 3:// Left
                dx=x;
                dy=y-1;
                move(board,&board[dx][dy],x,y,dx,dy);
                x=dx;
                y=dy;
                break;
            case 4:// Right
                dx=x;
                dy=y+1;
                move(board,&board[dx][dy],x,y,dx,dy);
                x=dx;
                y=dy;
                break;
            default:
                break;
        }
    }
    return 0;
}

// The Function for detail of Player move.
int move(square board [BOARD_SIZE][BOARD_SIZE],square * s,int x, int y, int dx, int dy)
{
    // Give a solution if player want move to invalid place.
    if(board[dx][dy].type==INVALID)
    {
        printf("Error! The target coordinates is invalid!\n");
        printf("Please replace it with another one!\n");
        return -1;
    }

    // If player choose the green piece.
    if(board[x][y].stack->p_color==GREEN)
    {
        player_color=1; //green
    }
    else
    {
        player_color=0;//red
    }

    // Maintain the size of each stack equal to 5
    if (board[x][y].num_pieces==5 && board[dx][dy].num_pieces != 0)
    {
        piece *top = NULL;
        piece *curr = NULL;
        piece *last = NULL;
        piece *toRemove = NULL;

        // Get target memory address.
        top = get_Ptr_stack(&board[dx][dy],board[x][y].num_pieces,board[dx][dy].num_pieces);
        board[dx][dy].stack = top;
        // Link current stuck to target one.
        top = push_with_stack(&board[x][y], top, s->num_pieces-1);
        board[dx][dy].stack = top;
        delete(&board[x][y]);// Delete previous coordinates.

        int count = 1;

        curr = top;
        while(curr != NULL)
        {
            if (count < 5)
            {
                curr = curr->next;
                count++;
            } else
            {
                last = curr;
                break;
            }
        }

        if(last != NULL)
        {
            curr = curr->next;
            while(curr!=NULL)
            {
                if(curr->p_color != player_color)
                {
                    Players[player_color].adv_captured ++;
                } else
                {
                    Players[player_color].own_kept ++;
                }
                toRemove = curr;
                curr = curr->next;
                free(toRemove);
            }
            last->next = NULL;
        }
        board[dx][dy].num_pieces = 5;
        print_board(board);// Print current new board.
        print_number_of_pieces(board);// print current new number of pieces.
        // Update player's own kept and captured pieces.
        print_kept_and_capt (player_color);
        return 0;
    }

    // Update player's own kept and captured pieces.
    if(board[x][y].num_pieces==1)// Player move piece
    {

        if(board[dx][dy].num_pieces==0)// target piece is close to the edge
        {
            print_kept_and_capt (player_color);
        //special case for move to edge.
            for (int i = 0; i < board[x][y].num_pieces ; ++i)
            {
                piece *top = NULL;
                // Get target memory address.
                top = get_Ptr_stack(&board[dx][dy],board[x][y].num_pieces,board[dx][dy].num_pieces);
                board[dx][dy].stack = top;
                // Link current stuck to target one.
                if(board[x][y].num_pieces==1)
                {
                    top = push(&board[x][y] ,top);
                } else
                {
                    top = push_with_stack(&board[x][y] ,top,board[x][y].num_pieces-1);
                }
                board[dx][dy].stack = top;
            }
            delete(&board[x][y]);// Delete previous coordinates.
            print_board(board);// Print current new board.
            print_number_of_pieces(board);// print current new number of pieces.
            return 0;
        }
        // Update player's own kept and captured pieces.
        print_kept_and_capt (player_color);
        piece *top = NULL;
        top = get_Ptr(&board[dx][dy]);// Get target memory address.
        top = push(&board[x][y] ,top);// Link current stuck to target one.
        board[dx][dy].stack = top;
        delete(&board[x][y]);// Delete previous coordinates.
        printf("top color(0red 1green):%d\n",board[dx][dy].stack->p_color);
        print_board(board);// Print current new board.
        print_number_of_pieces(board);// print current new number of pieces.
    }
    else // Player move stuck
    {
        // Update player's own kept and captured pieces.
        print_kept_and_capt (player_color);

        piece *top = NULL;
        // Get target memory address.
        top = get_Ptr_stack(&board[dx][dy],board[x][y].num_pieces,board[dx][dy].num_pieces);
        board[dx][dy].stack = top;
        // Link current stuck to target one.
        top = push_with_stack(&board[x][y], top, s->num_pieces-1);
        board[dx][dy].stack = top;
        delete(&board[x][y]);// Delete previous coordinates.
        print_board(board);// Print current new board.
        print_number_of_pieces(board);// print current new number of pieces.
    }
    return 0;
}

//Function print info, update player's own kept and captured pieces.
void print_kept_and_capt (int player__color)
{
    if(player__color == 0) // if player is red
    {
        if(flags.flag_0 == 0)// player[0]:red
        {
            update( 2, 0 ,1);// n:0 (player != get ) n:1(player == get) n:2( player -> egde)
        }
        else if (flags.flag_1 == 0)// player[1]:red
        {
            update( 2, 1 ,0);// n:0 (player != get ) n:1(player == get) n:2( player -> egde)
        }
    }
    else // if player is green
    {
        if(flags.flag_0 == 1)// player[0]:green
        {
            update( 2, 0 ,1);// n:0 (player != get ) n:1(player == get) n:2( player -> egde)
        }
        else if (flags.flag_1 == 1)// player[1]:green
        {
            update( 2, 1 ,0);// n:0 (player != get ) n:1(player == get) n:2( player -> egde)
        }
    }
}

// Function for link current stuck to target one.
piece * push(square * s, piece *top)
{
    piece * destination = top;
    top = malloc(sizeof(piece));
    top->p_color = get_Col(s);
    top->next = destination;
    s->num_pieces --;
    s->stack->p_color = get_Col(s);
    return top;
}

// Function for link current stuck to target one. (multi)
piece * push_with_stack(square * s, piece *top, int num)
{
    piece * destination = top;
    switch (num)
    {
        case 1:
            top = s->stack;
            top->next = destination;
            s->num_pieces -=s->num_pieces;
            return top;
        case 2:
            top = s->stack;
            top->next->next = destination;
            s->num_pieces -=s->num_pieces;
            return top;
        case 3:
            top = s->stack;
            top->next->next->next = destination;
            s->num_pieces -=s->num_pieces;
            return top;
        case 4:
            top = s->stack;
            top->next->next->next->next = destination;
            s->num_pieces -=s->num_pieces;
            return top;
        case 5:
            top = s->stack;
            top->next->next->next->next->next = destination;
            s->num_pieces -=s->num_pieces;
            return top;
        default:
            return 0;
    }
}

// Function for get target memory address.
piece * get_Ptr (square * s)
{
    s->num_pieces ++;
    if (s->stack==NULL)// A piece/stack can be placed correctly on an empty square
    {
        return malloc(sizeof(piece));
    }
    return s->stack;
}
piece * get_Ptr_stack (square * s,int num_1, int num_2)
{
    s->num_pieces = num_1 + num_2;
    if (s->stack==NULL)// A piece/stack can be placed correctly on an empty square
    {
        return malloc(sizeof(piece));
    }
    return s->stack;
}
// Function for get color of target position.
char get_Col (square * s)
{
    return s->stack->p_color;
}
// Delete the previous coordinates.
void delete (square * s)
{
    s->stack = ( s->stack )=NULL;
}

// Function for Update player's own kept and captured pieces.
void update(int n, int player_num, int opponent_num)
{
    int i = player_num;
    int o = opponent_num;
    if (n==0)
    {
        printf("Player:%s\n",&Players[i].Players_name[i]);
        printf("*Number of own pieces kept: %d\n",Players[i].own_kept);
        Players[i].adv_captured ++;
        printf("*Number of adversary's pieces captured: %d\n",Players[i].adv_captured);
    //opponent:
        printf("Player:%s\n",&Players[o].Players_name[o]);
        printf("*Number of own pieces kept: %d\n",Players[o].own_kept);
        printf("*Number of adversary's pieces captured: %d\n",Players[o].adv_captured);
    } else if (n==1)
    {
        printf("Player:%s\n",&Players[i].Players_name[i]);
        Players[i].own_kept ++;
        printf("*Number of own pieces kept: %d\n",Players[i].own_kept);
        printf("*Number of adversary's pieces captured: %d\n",Players[i].adv_captured);
    //opponent:
        printf("Player:%s\n",&Players[o].Players_name[o]);
        printf("*Number of own pieces kept: %d\n",Players[o].own_kept);
        printf("*Number of adversary's pieces captured: %d\n",Players[o].adv_captured);
    }
    else if (n==2) // Regular update.
    {
        printf("Player:%s\n",&Players[i].Players_name[i]);
        printf("*Number of adversary's pieces captured: %d\n",Players[i].adv_captured);
        printf("*Number of own pieces kept: %d\n",Players[i].own_kept);
    //opponent:
        printf("Player:%s\n",&Players[o].Players_name[o]);
        printf("*Number of adversary's pieces captured: %d\n",Players[o].adv_captured);
        printf("*Number of own pieces kept: %d\n",Players[o].own_kept);
    }
}
// Function for check winner status.
int check_win (square board [BOARD_SIZE][BOARD_SIZE])
{
    int red_num = 0, green_num = 0;
    for (int i = 0; i <BOARD_SIZE; ++i)
    {
        for (int j = 0; j <BOARD_SIZE ; ++j)
        {
            if (board[i][j].type==VALID && board[i][j].stack != NULL)
            {// Count the total number of each color on the board.
                if(board[i][j].stack->p_color==RED)
                {
                    red_num++;//Accumulation of red.
                }
                else if (board[i][j].stack->p_color==GREEN)
                {
                    green_num++;//Accumulation of green.
                }
            }
        }
    }
    // feedback
    if (red_num <=1 && green_num >= 1)
    {
        return 0;// Green win.
    } else if (green_num <=1 && red_num >= 1)
    {
        return 1;// Red win.
    } else
    {
        return 2; // continue.
    }
}

// Move kept piece
void move_own_kept (square board [BOARD_SIZE][BOARD_SIZE], int color)
{
    int dx=0 , dy=0;
    printf("\n*************************************\n");
    printf("Now, You can move your kept pieces.\nTotal number of own kept: %d\n",Players[color].own_kept);
    printf("Please enter the corresponding abscissa \nof your own kept you want to place:\n");
    printf("(Column number)\n");
    scanf("%d", &dy);
    printf("Please enter the corresponding ordinate \nof your own kept you want to place:\n");
    printf("(Row number)\n");
    scanf("%d", &dx);
    // 1-8 on the command line board and 0-7 here, convert.
    dx-=1;
    dy-=1;

    piece *top = NULL;
    // Get target memory address.
    top = get_Ptr_stack(&board[dx][dy],1,board[dx][dy].num_pieces);
    board[dx][dy].stack = top;
    // Link current stuck to target one.
    piece * destination = top;
    top = malloc(sizeof(piece));
    top->p_color = color;
    top->next = destination;
    board[dx][dy].stack = top;
    Players[color].own_kept --;
    print_board(board);// Print current new board.
    print_number_of_pieces(board);
}
