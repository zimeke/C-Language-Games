# TicTacToe
This is a simple implementation of the classic TicTacToe game in C. Two players, Player 1 (X) and Player 2 (O), take turns to mark spaces on a 3x3 grid. The objective is to align three of the same symbols (X or O) either horizontally, vertically, or diagonally. The game ends when one player wins, or if the grid is filled with no winner, it results in a draw.

## Features
* 2-player game: Player 1 uses 'X' and Player 2 uses 'O'.
* Input validation: Only valid moves are accepted. If a player selects an already-taken spot, they are asked to try again.
* Win detection: The game checks for wins based on three aligned symbols.
* Draw condition: If all 9 spaces are filled with no winner, the game declares a draw.

## Usage
The game starts with Player 1's turn.
Each player enters a number (1-9) corresponding to the position on the grid where they want to place their mark.
After each move, the game board is updated and displayed.
The game continues until either a player wins or the grid is filled without a winner (draw).

## Code Explanation
* display(): This function clears the console and prints the current state of the TicTacToe board.
* validStep(): Checks if the player's move is valid (i.e., the spot hasn't been taken).
* playerStep(): Handles the player's input, validates it, and updates the board with either 'X' or 'O' depending on the player.
* ifWin(): Checks if the current player has aligned three symbols in a row, column, or diagonal.

## Future Improvements
* Add support for playing against the computer.
* Implement a graphical interface for the game.
