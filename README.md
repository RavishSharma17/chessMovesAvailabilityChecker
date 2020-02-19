# chessMovesAvailabilityChecker
A program to find all possible moves of a chess piece on an empty board.




The chessboard is an 8 x 8 grid with 64 cells in it. With 8 rows (A, B, C�. H) and 8 columns (1, 2, 3�. 8), each cell can be uniquely identified with its cell number.



Chess pieces and their movements: 

The game of chess has 6 unique types of pieces, with their own unique types of movements. These are: 
1.) King � Can move only 1 step at a time in all 8 directions (horizontal, vertical and diagonal).
 
2.) Queen � Can move across the board in all 8 directions 

3.) Bishop � Can move across the board only diagonally 

4.) Horse � Can move across the board only in 2.5 steps (2 vertical steps and 1 horizontal step) 

5.) Rook � Can move across the board only vertically and horizontally 

6.) Pawn � Can move only 1 step at a time, in the forward direction, vertically. 


Input � The input string to your program will be the Type of chess piece and its Position (cell number) on the chessboard. E.g. �King D5� 

Output � Once you execute the program, the output will be a string of all possible cells in which the chess piece can move.


Sample inputs and outputs: 
Input � �King D5� 
Output � �E5, E6, D6, C6, C5, C4, D4, E4�


Assumption: It is assumed that the board is empty.

