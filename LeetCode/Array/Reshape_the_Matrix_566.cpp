//LeetCode Link: https://leetcode.com/problems/reshape-the-matrix/

/*
1st solution
Complexity analysis:
* Time: O(N * M) where N and M are sizes of the old/new matrix
* Space: O(N * M) 
*/
class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int new_rows_count, int new_columns_count) {
        vector<vector<int>> reshaped;
        int old_rows_count = nums.size();
        int old_columns_count = nums[0].size();
        
        if (new_rows_count <= 0 || new_columns_count <= 0) {
            //invalid input
            return nums;
        } 
        else if (old_rows_count == new_rows_count || old_columns_count == new_columns_count) {
            /*
            this if-statement includes a case when old sizes are equal to new ones => it is the same matrix
            and a case where only one new size are equal to old one => we can't reshape the matrix
            */
            return nums;
        }
        else if (old_rows_count * old_columns_count != new_rows_count * new_columns_count) {
            //the amount of elements in old matrix and requested one is different
            return nums;
        }
        
        list<int> all_elements;
        
        for (auto row : nums) {
            for (auto col : row) {
                all_elements.push_back(col);
            }
        }
        
        auto current_element_iterator = all_elements.begin();
        
        for (int row_index = 0; row_index < new_rows_count; ++row_index) {
            vector<int> current_row;
            
            for (int col_index = 0; col_index < new_columns_count; ++col_index) {
                current_row.push_back(*current_element_iterator);
                ++current_element_iterator;
            }
            
            reshaped.push_back(current_row);
        }
        
        return reshaped; 
    }
};

/*
2nd solution
Complexity analysis:
* Time: O(N * M) where N and M are sizes of the old/new matrix
* Space: O(1) 
*/
class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int new_rows_count, int new_columns_count) {
        vector<vector<int>> reshaped;
        int old_rows_count = nums.size();
        int old_columns_count = nums[0].size();
        
        if (new_rows_count <= 0 || new_columns_count <= 0) {
            //invalid input
            return nums;
        } 
        else if (old_rows_count == new_rows_count || old_columns_count == new_columns_count) {
            /*
            this if-statement includes a case when old sizes are equal to new ones => it is the same matrix
            and a case where only one new size are equal to old one => we can't reshape the matrix
            */
            return nums;
        }
        else if (old_rows_count * old_columns_count != new_rows_count * new_columns_count) {
            //the amount of elements in old matrix and requested one is different
            return nums;
        }
        
        int current_old_row = 0;
        auto current_element_iterator = nums[current_old_row].begin();
        
        for (int row_index = 0; row_index < new_rows_count; ++row_index) {
            vector<int> current_row;
            
            for (int col_index = 0; col_index < new_columns_count; ++col_index) {
                if (current_element_iterator == nums[current_old_row].end()) {
                    current_old_row += 1;
                    current_element_iterator = nums[current_old_row].begin();
                }
                current_row.push_back(*current_element_iterator);
                ++current_element_iterator;
            }
            
            reshaped.push_back(current_row);
        }
        
        
        return reshaped; 
    }
};
