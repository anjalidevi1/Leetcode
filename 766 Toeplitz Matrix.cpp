//Given an m x n matrix, return true if the matrix is Toeplitz. Otherwise, return false.

A matrix is Toeplitz if every diagonal from top-left to bottom-right has the same elements.

 

Example 1:


Input: matrix = [[1,2,3,4],[5,1,2,3],[9,5,1,2]]
Output: true
Explanation:
In the above grid, the diagonals are:
"[9]", "[5, 5]", "[1, 1, 1]", "[2, 2, 2]", "[3, 3]", "[4]".
In each diagonal all elements are the same, so the answer is True.
Example 2:


Input: matrix = [[1,2],[2,2]]
Output: false
Explanation:
The diagonal "[1, 2]" has different elements.
 

Constraints:

m == matrix.length
n == matrix[i].length
1 <= m, n <= 20
0 <= matrix[i][j] <= 99
 

Follow up:

What if the matrix is stored on disk, and the memory is limited such that you can only load at most one row of the matrix into the memory at once?
What if the matrix is so large that you can only load up a partial row into the memory at once?


class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        
    int m = matrix.size();
        int n = matrix[0].size();
        
        // Check all diagonals starting from the first row
        for (int j = 0; j < n; ++j) {
            int value = matrix[0][j];
            int x = 0, y = j;
            while (x < m && y < n) {
                if (matrix[x][y] != value) {
                    return false;
                }
                ++x;
                ++y;
            }
        }
        
        // Check all diagonals starting from the first column (excluding the top-left corner)
        for (int i = 1; i < m; ++i) {
            int value = matrix[i][0];
            int x = i, y = 0;
            while (x < m && y < n) {
                if (matrix[x][y] != value) {
                    return false;
                }
                ++x;
                ++y;
            }
        }
        
        return true;
    }
};
