# Tic-Tac-Toe

A classic command-line implementation of the Tic-Tac-Toe game for two players (X and O). The game features an interactive board, move validation, win detection, and draw detection.

## Features
- **Two-Player Gameplay**: Play as 'X' and 'O'.
- **Interactive Board**: Displays the current state of the board after each move.
- **Move Validation**: Ensures players choose valid, unoccupied cells (1-9).
- **Win/Draw Detection**: Automatically detects when a player wins or the game ends in a draw.
- **Replayability**: Option to play multiple rounds.

## How to Run

### Compilation
Use a C++ compiler like `g++` to compile the source code:

```bash
g++ main.cpp -o tic_tac_toe
```

### Execution
Run the compiled executable:

```bash
./tic_tac_toe
```

## Example Gameplay

```bash
=== TIC TAC TOE ===
Player X  vs  Player O

   |   |   
 1 | 2 | 3 
---+---+---
 4 | 5 | 6 
---+---+---
 7 | 8 | 9 
   |   |   

Player X's turn
> 1

=== TIC TAC TOE ===
Player X  vs  Player O

   |   |   
 X | 2 | 3 
---+---+---
 4 | 5 | 6 
---+---+---
 7 | 8 | 9 
   |   |   

Player O's turn
> 5

=== TIC TAC TOE ===
Player X  vs  Player O

   |   |   
 X | 2 | 3 
---+---+---
 4 | O | 6 
---+---+---
 7 | 8 | 9 
   |   |   

Player X's turn
> 2

=== TIC TAC TOE ===
Player X  vs  Player O

   |   |   
 X | X | 3 
---+---+---
 4 | O | 6 
---+---+---
 7 | 8 | 9 
   |   |   

Player O's turn
> 4

=== TIC TAC TOE ===
Player X  vs  Player O

   |   |   
 X | X | 3 
---+---+---
 O | O | 6 
---+---+---
 7 | 8 | 9 
   |   |   

Player X's turn
> 3

=== TIC TAC TOE ===

   |   |   
 X | X | X 
---+---+---
 O | O | 6 
---+---+---
 7 | 8 | 9 
   |   |   

Player X wins!

Play again? (y/n): n
Thanks for playing!
```
