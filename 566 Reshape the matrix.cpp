//In MATLAB, there is a handy function called reshape which can reshape an m x n matrix into a new one with a different size r x c keeping its original data.

You are given an m x n matrix mat and two integers r and c representing the number of rows and the number of columns of the wanted reshaped matrix.

The reshaped matrix should be filled with all the elements of the original matrix in the same row-traversing order as they were.

If the reshape operation with given parameters is possible and legal, output the new reshaped matrix; Otherwise, output the original matrix.

 

Example 1:


Input: mat = [[1,2],[3,4]], r = 1, c = 4
Output: [[1,2,3,4]]
Example 2:


Input: mat = [[1,2],[3,4]], r = 2, c = 4
Output: [[1,2],[3,4]]
 

Constraints:

m == mat.length
n == mat[i].length
1 <= m, n <= 100
-1000 <= mat[i][j] <= 1000
1 <= r, c <= 300

class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
               int m = mat.size();
        int n = mat[0].size();
        
        // Check if reshape operation is possible
        if (m * n != r * c) {
            return mat;
        }
        
        // Create the new reshaped matrix
        std::vector<std::vector<int>> reshapedMatrix(r, std::vector<int>(c));
        int currentRow = 0;
        int currentCol = 0;
        
        // Fill the reshaped matrix with elements from the original matrix
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                reshapedMatrix[currentRow][currentCol] = mat[i][j];
                currentCol++;
                if (currentCol == c) {
                    currentCol = 0;
                    currentRow++;
                }
            }
        }
        
        return reshapedMatrix;
    }
};