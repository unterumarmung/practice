//LeetCode link: https://leetcode.com/problems/house-robber/

class Solution {
public:
    int rob(vector<int>& nums) {
        int size = nums.size();
        
        if(size == 0) return 0;
        if(size == 1) return nums[0];
        if(size == 2) return max(nums[0], nums[1]);
        
        long int dp[size];
        
        dp[0] = nums[0];
        dp[1] = nums[1];
        dp[2] = nums[0] + nums[2];
        
        for(int i = 3; i < size; ++i){
            dp[i] = std::max(dp[i-2], dp[i-3]) + nums[i];
        }
        
        return max(dp[size-1], dp[size-2]);
    }
};