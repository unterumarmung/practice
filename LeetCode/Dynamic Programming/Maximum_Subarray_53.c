//LeetCode Link: https://leetcode.com/problems/maximum-subarray/

int max(int val1, int val2) {
    return (val1 > val2) ? val1 : val2;
}

/*
1st solution
Complexity analysis:
* Time: O(size)
* Space: O(size)
*/
int maxSubArray(int* nums, int size) {
    int* dp = (int*)malloc(size * sizeof(int));
    dp[0] = nums[0];
    int max_subarray = dp[0];
    
    for (int i = 1; i < size; ++i) {
        dp[i] = max(nums[i], dp[i - 1] + nums[i]);
        max_subarray = max(max_subarray, dp[i]);
    }
    
    free(dp);
    return max_subarray;
}

/*
1st solution
Complexity analysis:
* Time: O(size)
* Space: O(1)
*/
int maxSubArray(int* nums, int size) {
    int current; 
    int previous = nums[0]; 
    int max_subarray = previous;
    
    for (int i = 1; i < size; ++i) {
        current = max(nums[i], previous + nums[i]);
        max_subarray = max(max_subarray, current);
        previous = current;
    }
    
    return max_subarray;
}