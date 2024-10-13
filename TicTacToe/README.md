# TicTacToe
This is a simple implementation of the classic TicTacToe game in C. Two players, Player 1 (X) and Player 2 (O), take turns to mark spaces on a 3x3 grid. The objective is to align three of the same symbols (X or O) either horizontally, vertically, or diagonally. The game ends when one player wins, or if the grid is filled with no winner, it results in a draw.

## Code Explanation
* display(): This function clears the console and prints the current state of the TicTacToe board.
* validStep(): Checks if the player's move is valid (i.e., the spot hasn't been taken).
* playerStep(): Handles the player's input, validates it, and updates the board with either 'X' or 'O' depending on the player.
* ifWin(): Checks if the current player has aligned three symbols in a row, column, or diagonal.

## Future Improvements
* Add support for playing against the computer.
* Implement a graphical interface for the game.
