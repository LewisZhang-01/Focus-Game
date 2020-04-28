//
// Created by Lewis Zhang on 21/04/2020.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "game_run.h"
#include "input_output.h"
#include "game_init.h"


player_flag flags;
player Players[PLAYERS_NUM];
int first=0;
int check = 0;

int turn(player players[PLAYERS_NUM],int tag)
{

    //Players->Players_name[1]=players->Players_name[1];
    if (first == 0)
    {
        strcpy(&Players[0].Players_name[0],&players[0].Players_name[0]);
        strcpy(&Players[1].Players_name[1],&players[1].Players_name[1]);

        if (players[0].player_color == RED) {
            // Output players' turn.
            switch (players[0].player_color) {// Print user choice.
                case (RED):// if player choose red then print red.
                    printf("Now it's %s's turn (%s side)!\n", &players[0].Players_name[0], "Red");
                    break;
                case (GREEN):// if player choose green then print green.
                    printf("Now it's %s's turn (%s side)!\n", &players[0].Players_name[0], "Green");
                    break;
                default:
                    break;
            }
            flags.flag_0 = 0;// red
            flags.flag_1 = 1;// green
            first++;
            return 1;
        } else if (players[1].player_color == RED) {
            switch (players[1].player_color) {// Print user choice.
                case (RED):// if player choose red then print red.
                    printf("Now it's %s's turn (%s side)!\n", &players[1].Players_name[1], "Red");
                    break;
                case (GREEN):// if player choose green then print green.
                    printf("Now it's %s's turn (%s side)!\n", &players[1].Players_name[1], "Green");
                    break;
                default:
                    break;
            }// Output players' turn.
            flags.flag_1 = 0;// red
            flags.flag_0 = 1;// green
            first++;

            return 0;
        }
    }

    if (tag == 0) {
        switch (players[0].player_color) {// Print user choice.
            case (RED):// if player choose red then print red.
                printf("Now it's %s's turn (%s side)!\n", &players[0].Players_name[0], "Red");
                break;
            case (GREEN):// if player choose green then print green.
                printf("Now it's %s's turn (%s side)!\n", &players[0].Players_name[0], "Green");
                break;
            default:
                break;
        }
        return 1;
    } else if (tag == 1)
    {
        switch (players[1].player_color) {// Print user choice.
            case (RED):// if player choose red then print red.
                printf("Now it's %s's turn (%s side)!\n", &players[1].Players_name[1], "Red");
                break;
            case (GREEN):// if player choose green then print green.
                printf("Now it's %s's turn (%s side)!\n", &players[1].Players_name[1], "Green");
                break;
            default:
                break;
        }
        return 0;
    }
    return 0;
}

// Player 1 move
void Player_1_Move(square board [BOARD_SIZE][BOARD_SIZE])
{
    int x = 0;
    int y = 0;
    int dx = 0;
    int dy = 0;
    int choice = 0;

    int pass = 0;

    while(pass==0)
    {
        printf("Please enter the corresponding abscissa of the piece/stack you want to move:");
        printf("(Column number)\n");
        scanf("%d", &y);
        printf("Please enter the corresponding ordinate of the piece/stack you want to move:");
        printf("(Row number)\n");
        scanf("%d", &x);
        x-=1;
        y-=1;

        if (((x == 0 && (y<=1 || y>=6))||(x == 1 && (y<0 || y>7))||(x == 6 && (y<0 || y>7))||(x == 7 && (y<=1 || y>=6))) || x<0 || x > BOARD_SIZE || y < 0 || y > BOARD_SIZE || dx < 0 || dx > BOARD_SIZE || dy < 0 || dy > BOARD_SIZE)
        {
            printf("Error! This coordinates is invalid!\n");
            printf("Please replace it with another one:\n");
            pass = 0;

        }
        else
        {
            pass = 1;
        }
    }

    int num =board[x][y].num_pieces;
    printf("The total number in your choose stack is %d, so you can move %d step(s).\n ",num,num);


    for (int i = 0; i < num; ++i)
    {
        printf("%d/%d\nIf you want:\n1.Up\n2.Down\n3.Left\n4.Right\n",i+1,num);
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
}

// Player move
int move(square board [BOARD_SIZE][BOARD_SIZE],square * s,int x, int y, int dx, int dy)
{
    int player_color;
    char p_c;

    if(board[dx][dy].type==INVALID)
    {
        printf("Error! The target coordinates is invalid!\n");
        printf("Please replace it with another one!\n");
        return -1;
    }

    if(board[x][y].stack->p_color==GREEN)//if player choose the green piece
    {
        player_color=1; //green
        p_c = GREEN;
    }
    else
    {
        player_color=0;//red
        p_c = RED;
    }

    if (board[x][y].num_pieces==5)// maintain the size of each stack equal to 5
    {
        char temp = board[dx][dy].stack->p_color;
        if (strcmp(&temp, &p_c) == 0)// next one is current player's piece
        {
            if(player_color == 0) // if player is red
            {
                if(flags.flag_0 == 0)// player[0]:red
                {
                    update(Players, 1, 0 ,1);// n:0 ( captured ) n:1( kept ) n:2( player -> egde)
                }
                else if (flags.flag_1 == 0)// player[1]:red
                {
                    update(Players, 1, 1 ,0);// n:0 ( captured ) n:1( kept ) n:2( player -> egde)
                }
            }
            else // if player is green
            {
                if(flags.flag_0 == 1)// player[0]:green
                {
                    update(Players, 1, 0 ,1);// n:0 ( captured ) n:1( kept ) n:2( player -> egde)
                }
                else if (flags.flag_1 == 1)// player[1]:green
                {
                    update(Players, 1, 1 ,0);// n:0 ( captured ) n:1( kept ) n:2( player -> egde)
                }
            }
        } else // next one is not current player's piece
        {
            if(player_color == 0) // if player is red
            {
                if(flags.flag_0 == 0)// player[0]:red
                {
                    update(Players, 0, 0 ,1);// n:0 ( captured ) n:1( kept ) n:2( player -> egde)
                }
                else if (flags.flag_1 == 0)// player[1]:red
                {
                    update(Players, 0, 1 ,0);// n:0 ( captured ) n:1( kept ) n:2( player -> egde)
                }
            }
            else // if player is green
            {
                if(flags.flag_0 == 1)// player[0]:green
                {
                    update(Players, 0, 0 ,1);// n:0 ( captured ) n:1( kept ) n:2( player -> egde)
                }
                else if (flags.flag_1 == 1)// player[1]:green
                {
                    update(Players, 0, 1 ,0);// n:0 ( captured ) n:1( kept ) n:2( player -> egde)
                }
            }
        }

        int num=0;

        for (int i = 0; i < board[x][y].num_pieces ; ++i)
        {
            piece *top = NULL;
            piece *tem = NULL;
            int d_num = board[dx][dy].num_pieces;
            tem = top = get_Ptr_stack(&board[dx][dy],board[x][y].num_pieces,board[dx][dy].num_pieces);
            board[dx][dy].stack = top;
            if(board[x][y].num_pieces==1)
            {
                top = push(&board[x][y] ,top);
            } else
            {
                top = push_with_stack(&board[x][y], top, board[x][y].num_pieces-1);
            }

            board[dx][dy].stack = top;
            delete(&board[x][y],tem);
            num = s->num_pieces - d_num;
        }




        delete_more(&board[x][y],num);

        print_board(board);
        print_number_of_pieces(board);


        return 0;
    }

    if(board[x][y].num_pieces==1)// Player move piece
    {
        if(board[dx][dy].num_pieces==0)// target piece is close to the edge
        {
            if(player_color == 0) // if player is red
            {
                if(flags.flag_0 == 0)// player[0]:red
                {
                    update(Players, 2, 0 ,1);// n:0 (player != get ) n:1(player == get) n:2( player -> egde)
                }
                else if (flags.flag_1 == 0)// player[1]:red
                {
                    update(Players, 2, 1 ,0);// n:0 (player != get ) n:1(player == get) n:2( player -> egde)
                }
            }
            else // if player is green
            {
                if(flags.flag_0 == 1)// player[0]:green
                {
                    update(Players, 2, 0 ,1);// n:0 (player != get ) n:1(player == get) n:2( player -> egde)
                }
                else if (flags.flag_1 == 1)// player[1]:green
                {
                    update(Players, 2, 1 ,0);// n:0 (player != get ) n:1(player == get) n:2( player -> egde)
                }
            }

            int num=0;

            for (int i = 0; i < board[x][y].num_pieces ; ++i)
            {
                piece *top = NULL;
                top = get_Ptr_stack(&board[dx][dy],board[x][y].num_pieces,board[dx][dy].num_pieces);
                board[dx][dy].stack = top;
                if(board[x][y].num_pieces==1)
                {
                    top = push(&board[x][y] ,top);
                } else
                {
                    top = push_with_stack(&board[x][y] ,top,board[x][y].num_pieces-1);
                }

                board[dx][dy].stack = top;
                num = s->num_pieces;
            }

            delete_more(&board[x][y],num);

            print_board(board);
            print_number_of_pieces(board);

            return 0;
        }
        if(player_color == 0) // if player is red
        {
            if(flags.flag_0 == 0)// player[0]:red
            {
                update(Players, 2, 0 ,1);// n:0 (player != get ) n:1(player == get) n:2( player -> egde)
            }
            else if (flags.flag_1 == 0)// player[1]:red
            {
                update(Players, 2, 1 ,0);// n:0 (player != get ) n:1(player == get) n:2( player -> egde)
            }
        }
        else // if player is green
        {
            if(flags.flag_0 == 1)// player[0]:green
            {
                update(Players, 2, 0 ,1);// n:0 (player != get ) n:1(player == get) n:2( player -> egde)
            }
            else if (flags.flag_1 == 1)// player[1]:green
            {
                update(Players, 2, 1 ,0);// n:0 (player != get ) n:1(player == get) n:2( player -> egde)
            }
        }
        int num=0;
        piece *top = NULL;
        top = get_Ptr(&board[dx][dy]);
        top = push(&board[x][y] ,top);
        board[dx][dy].stack = top;
        num = s->num_pieces;
        delete_more(&board[x][y],num-1);
        printf("top color(0red 1green):%d\n",board[dx][dy].stack->p_color);
        print_board(board);
        print_number_of_pieces(board);
    }
    else // Player move stuck
    {
        if(player_color == 0) // if player is red
        {
            if(flags.flag_0 == 0)// player[0]:red
            {
                update(Players, 2, 0 ,1);// n:0 (player != get ) n:1(player == get) n:2( player -> egde)
            }
            else if (flags.flag_1 == 0)// player[1]:red
            {
                update(Players, 2, 1 ,0);// n:0 (player != get ) n:1(player == get) n:2( player -> egde)
            }
        }
        else // if player is green
        {
            if(flags.flag_0 == 1)// player[0]:green
            {
                update(Players, 2, 0 ,1);// n:0 (player != get ) n:1(player == get) n:2( player -> egde)
            }
            else if (flags.flag_1 == 1)// player[1]:green
            {
                update(Players, 2, 1 ,0);// n:0 (player != get ) n:1(player == get) n:2( player -> egde)
            }
        }

        int num=0;

        for (int i = 0; i < board[x][y].num_pieces ; ++i)
        {
            piece *top = NULL;
            top = get_Ptr_stack(&board[dx][dy],board[x][y].num_pieces,board[dx][dy].num_pieces);
            board[dx][dy].stack = top;

            top = push_with_stack(&board[x][y], top, s->num_pieces-1);
            board[dx][dy].stack = top;
            num = s->num_pieces;
        }

        delete_more(&board[x][y],num);

        printf("top color(0red 1green):%d\n",board[dx][dy].stack->p_color);
        print_board(board);
        print_number_of_pieces(board);
    }

    return 0;
}

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

piece * push_with_stack(square * s, piece *top, int num)
{
    piece * destination = top;
    piece * temp = s->stack;
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
        default:
            return 0;
    }



}

piece * get_Ptr (square * s)
{
    s->num_pieces ++;
    if (s->stack==NULL)
    {
        check=1;
        return malloc(sizeof(piece));
    }
    return s->stack;
}
piece * get_Ptr_stack (square * s,int num_1, int num_2)
{
    s->num_pieces = num_1 + num_2;
    if (s->stack==NULL)
    {
        check=1;
        return malloc(sizeof(piece));
    }
    return s->stack;
}
char get_Col (square * s)
{
    return s->stack->p_color;
}

void delete (square * s,piece *temp)
{
    piece * temp_ = NULL;/* hold onto node being removed */
    piece * temp_pre = s->stack;
    while ( s->stack->next != temp  )
    {
        temp_pre = s->stack->next; /* walk to ... */
        s->stack->next = s->stack->next->next; /* ... next node */
    } /* end while */

    /* delete node at currentPtr */
    if ( s->stack->next == temp )
    {
        temp_ = s->stack->next;
        temp_pre->next = s->stack->next->next;
        free(temp_);
    }
}
void delete_more (square * s, int num)
{
    piece * temp = s->stack;
    switch (num)
    {
        case 1:
            s->stack = ( s->stack )->next; /* de-thread the node */
            free( temp ); /* free the de-threaded node */
            break;
        case 2:
            s->stack = ( s->stack )->next->next; /* de-thread the node */
            free( temp ); /* free the de-threaded node */
            break;
        case 3:
            s->stack = ( s->stack )->next->next->next; /* de-thread the node */
            free( temp ); /* free the de-threaded node */
            break;
        case 4:
            s->stack = ( s->stack )->next->next->next->next; /* de-thread the node */
            free( temp ); /* free the de-threaded node */
            break;
        case 5:
            s->stack = ( s->stack )->next->next->next->next->next->next; /* de-thread the node */
            free( temp ); /* free the de-threaded node */
            break;
        default:
            break;
    }

}



void update(player Players[PLAYERS_NUM],int n, int player_num, int opponent_num)
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
    else if (n==2) // When move piece to edge.
    {// as usual.
        printf("Player:%s\n",&Players[i].Players_name[i]);
        printf("*Number of adversary's pieces captured: %d\n",Players[i].adv_captured);
        printf("*Number of own pieces kept: %d\n",Players[i].own_kept);
//opponent:
        printf("Player:%s\n",&Players[o].Players_name[o]);
        printf("*Number of adversary's pieces captured: %d\n",Players[o].adv_captured);
        printf("*Number of own pieces kept: %d\n",Players[o].own_kept);
    }

}


int check_win (square board [BOARD_SIZE][BOARD_SIZE])
{
    int red_num = 0, green_num = 0;
    for (int i = 0; i <BOARD_SIZE; ++i)
    {
        for (int j = 0; j <BOARD_SIZE ; ++j)
        {
            if (board[i][j].type==VALID && board[i][j].stack != NULL)
            {
                char color = board[i][j].stack->p_color;
                char c_red = RED;
                if(board[i][j].stack->p_color==RED)
                {
                    red_num++;
                }
                else if (board[i][j].stack->p_color==GREEN)
                {
                    green_num++;
                }
            }

        }
    }
    if ((red_num <=1 && green_num >= 1)||(red_num==0))
    {// Green win
        return 0;
    } else if ((green_num <=1 && red_num >= 1)||(green_num==0))
    {// Red win
        return 1;
    } else
    {
        return 2; // continue
    }
}
