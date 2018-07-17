//LeetCode Link: https://leetcode.com/problems/climbing-stairs/

/*
Comlexity analysis:
* Time: O(n)
* Space: O(n)
*/
int climbStairs(int n) {
    int* dp = (int*)malloc(n * sizeof(int));
    dp[0] = 1;
    dp[1] = 2;
    
    for (int i = 2; i < n; ++i) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    
    free(dp);

    return dp[n - 1];
}