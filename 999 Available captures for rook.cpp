//You are given an 8 x 8 matrix representing a chessboard. There is exactly one white rook represented by 'R', some number of white bishops 'B', and some number of black pawns 'p'. Empty squares are represented by '.'.

A rook can move any number of squares horizontally or vertically (up, down, left, right) until it reaches another piece or the edge of the board. A rook is attacking a pawn if it can move to the pawn's square in one move.

Note: A rook cannot move through other pieces, such as bishops or pawns. This means a rook cannot attack a pawn if there is another piece blocking the path.

Return the number of pawns the white rook is attacking.

 

Example 1:


Input: board = [[".",".",".",".",".",".",".","."],[".",".",".","p",".",".",".","."],[".",".",".","R",".",".",".","p"],[".",".",".",".",".",".",".","."],[".",".",".",".",".",".",".","."],[".",".",".","p",".",".",".","."],[".",".",".",".",".",".",".","."],[".",".",".",".",".",".",".","."]]

Output: 3

Explanation:

In this example, the rook is attacking all the pawns.

Example 2:


Input: board = [[".",".",".",".",".",".","."],[".","p","p","p","p","p",".","."],[".","p","p","B","p","p",".","."],[".","p","B","R","B","p",".","."],[".","p","p","B","p","p",".","."],[".","p","p","p","p","p",".","."],[".",".",".",".",".",".",".","."],[".",".",".",".",".",".",".","."]]

Output: 0

Explanation:

The bishops are blocking the rook from attacking any of the pawns.

Example 3:


Input: board = [[".",".",".",".",".",".",".","."],[".",".",".","p",".",".",".","."],[".",".",".","p",".",".",".","."],["p","p",".","R",".","p","B","."],[".",".",".",".",".",".",".","."],[".",".",".","B",".",".",".","."],[".",".",".","p",".",".",".","."],[".",".",".",".",".",".",".","."]]

Output: 3

Explanation:

The rook is attacking the pawns at positions b5, d6, and f5.

 

Constraints:

board.length == 8
board[i].length == 8
board[i][j] is either 'R', '.', 'B', or 'p'
There is exactly one cell with board[i][j] == 'R'


#include <vector>

class Solution {
public:
    int numRookCaptures(std::vector<std::vector<char>>& board) {
        int rookRow = -1, rookCol = -1;
        // Locate the rook
        for (int i = 0; i < 8; ++i) {
            for (int j = 0; j < 8; ++j) {
                if (board[i][j] == 'R') {
                    rookRow = i;
                    rookCol = j;
                    break;
                }
            }
            if (rookRow != -1) break;
        }
        
        int numPawns = 0;
        // Check upwards from the rook's position
        for (int i = rookRow - 1; i >= 0; --i) {
            if (board[i][rookCol] == 'B') break;
            if (board[i][rookCol] == 'p') {
                numPawns++;
                break;
            }
        }
        
        // Check downwards from the rook's position
        for (int i = rookRow + 1; i < 8; ++i) {
            if (board[i][rookCol] == 'B') break;
            if (board[i][rookCol] == 'p') {
                numPawns++;
                break;
            }
        }
        
        // Check left from the rook's position
        for (int j = rookCol - 1; j >= 0; --j) {
            if (board[rookRow][j] == 'B') break;
            if (board[rookRow][j] == 'p') {
                numPawns++;
                break;
            }
        }
        
        // Check right from the rook's position
        for (int j = rookCol + 1; j < 8; ++j) {
            if (board[rookRow][j] == 'B') break;
            if (board[rookRow][j] == 'p') {
                numPawns++;
                break;
            }
        }
        
        return numPawns;
    }
};
