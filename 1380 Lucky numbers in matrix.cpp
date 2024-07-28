//Given an m x n matrix of distinct numbers, return all lucky numbers in the matrix in any order.

A lucky number is an element of the matrix such that it is the minimum element in its row and maximum in its column.

 

Example 1:

Input: matrix = [[3,7,8],[9,11,13],[15,16,17]]
Output: [15]
Explanation: 15 is the only lucky number since it is the minimum in its row and the maximum in its column.
Example 2:

Input: matrix = [[1,10,4,2],[9,3,8,7],[15,16,17,12]]
Output: [12]
Explanation: 12 is the only lucky number since it is the minimum in its row and the maximum in its column.
Example 3:

Input: matrix = [[7,8],[1,2]]
Output: [7]
Explanation: 7 is the only lucky number since it is the minimum in its row and the maximum in its column.
 

Constraints:

m == mat.length
n == mat[i].length
1 <= n, m <= 50
1 <= matrix[i][j] <= 105.
All elements in the matrix are distinct.

class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
         int m = matrix.size();
        int n = matrix[0].size();
        std::vector<int> rowMin(m, INT_MAX); // Vector to store min of each row
        std::vector<int> colMax(n, INT_MIN); // Vector to store max of each column

        // Step 1: Find the minimum element in each row
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                rowMin[i] = std::min(rowMin[i], matrix[i][j]);
            }
        }

        // Step 2: Find the maximum element in each column
        for (int j = 0; j < n; ++j) {
            for (int i = 0; i < m; ++i) {
                colMax[j] = std::max(colMax[j], matrix[i][j]);
            }
        }

        // Step 3: Collect all elements that are both rowMin and colMax
        std::vector<int> luckyNumbers;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (matrix[i][j] == rowMin[i] && matrix[i][j] == colMax[j]) {
                    luckyNumbers.push_back(matrix[i][j]);
                }
            }
        }

        return luckyNumbers;
    }
};
