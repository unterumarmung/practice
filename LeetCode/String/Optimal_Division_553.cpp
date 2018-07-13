//LeetCode link: https://leetcode.com/problems/optimal-division/

/*
Comlexity analysis:
* Time: O(N)
* Memory: O(N)
*/
class Solution {
public:
    string optimalDivision(vector<int>& nums) {
        const int nums_size = nums.size();
        string result_expression = "";
        
        if (nums_size == 0) return result_expression; //returns an empty string
        if (nums_size == 1) return to_string(nums[0]); 
        if (nums_size == 2) return to_string(nums[0]) + "/" + to_string(nums[1]);
        
        //adding first and second nums to result string
        result_expression += to_string(nums[0]) + "/(" + to_string(nums[1]) + "/"; 
        
        //adding "middle" elements
        for (int num = 2; num < nums_size - 1; ++num) {
            result_expression += to_string(nums[num]) + "/";
        }
        
        //adding last element
        result_expression += to_string(nums.back()) + ")";
        
        return result_expression;
    }
};