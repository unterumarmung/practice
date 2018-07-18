//LeetCode Link: https://leetcode.com/problems/transpose-matrix/

/*
Complexity analysis:
* Time: O(N * M)
* Space: O(N * M)
where N and M are sizes of the matrix
*/
class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        int old_height = matrix.size();
        int old_width = matrix[0].size();
        int new_height = old_width;
        int new_width = old_height;
        
        vector<vector<int>> transposed;
        
        for (int col = 0; col < old_width; ++col) {
            vector<int> current_row;
            for (int row = 0; row < old_height; ++row) {
                current_row.push_back(matrix[row][col]);
            }
            transposed.push_back(current_row);
        }
        
        return transposed;
    }
};