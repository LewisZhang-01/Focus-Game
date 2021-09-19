# Focus/Domination Board Game
<div align="center">    
   <img src="https://upload.wikimedia.org/wikipedia/commons/6/69/Focus_2.jpg" width = 450 height = 450>
   
  <br>[![](https://img.shields.io/badge/author-ZhiZhang-red "author")](https://github.com/LewisZhang-01/)
  ![](https://img.shields.io/badge/dynamic/json?label=GitHub%20Followers&query=%24.data.totalSubs&url=https%3A%2F%2Fapi.spencerwoo.com%2Fsubstats%2F%3Fsource%3Dgithub%26queryKey%3DLewisZhang-01&labelColor=282c34&color=181717&logo=github&longCache=true "followers")
  ![](https://img.shields.io/badge/C-green.svg "JAVA")
</div>

## About The Project
This project is to design and implement a C language game called “Focus” which is a Command-Line 2D board game.

Objective of each player is to make moves and capture pieces in such a manner that their opponent(s) have no moves remaining. 

More details on the rules of the game can be found here on the [Wikipedia website](https://en.wikipedia.org/wiki/Focus_(board_game)).

## Preset & Usage
<div align="center">   
<img src="https://upload.wikimedia.org/wikipedia/commons/d/d4/Focus_01.svg" width = 450 height = 450>
</div>
We assume that the game can only be played by two players. Each player is associated with a colour (e.g., red and green).

Each player has 18 tokens that are initially placed on a checkboard with the three squares in each corner removed, thus forming a 6×6 board with 1×4 extensions on each side (see image on the left).

Note that initially only 1 token is placed in each square. The tokens are initially placed as shown in the image on the left.

Two players will have to be co-located and play from the same machine. And the player is required to interact with this program using the command line.

On his/her turn a player:
1. Selects a piece or a stack s/he wants to move. Each player can only move a piece of
his/her own colour or a stack that has a top piece of his/her own colour. If a player
cannot select any piece/stack to move, the other player wins the game.

2. If a single piece is selected, that piece can only be moved up, down, left, or right. If a stack is selected, the stack can be moved to a number of positions depending on the
size of the stack. For example, if the size of the stack is 4, that stack can be moved to a position computed by moving the stack​ <up, up, left, right>​ or ​<down, down, down, left>​.

3. When a stack grows over five pieces, pieces from the bottom of the stack are removed and kept by the current player, in order to bring the stack size back down to five pieces. Pieces of a player's own color that are kept by that player are reserved to re-enter the game at a later time, when the player cannot move any of his/her pieces or any stacks. Pieces of the opponent's color are kept as captured. Reserved pieces can be entered on a turn in any space on the board in place of making a move of pieces.

Please read this [instruction pdf](https://github.com/LewisZhang-01/Focus-Game/blob/master/Focus:Domination_Board_Game%20Instruction.pdf) file.

Also this video ​https://www.youtube.com/watch?v=zRIChfOqu4M​ clearly explains the rules of the game.

## Key C programming concepts including
  * Two-dimensional arrays
  * Data structures
  * Pointers
  * Stacks (preferably implemented as linked lists)

## Author info
Author Name: Zhi Zhang  
   
Email - [@Zhi](lewiszhang01@gmail.com) - lewiszhang01@gmail.com

Project Link: [https://github.com/LewisZhang-01/Focus-Game](https://github.com/LewisZhang-01/Focus-Game)
