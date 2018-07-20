//LeetCode Link: https://leetcode.com/problems/find-pivot-index/

/*
Complexity analysis:
* Time: O(nums.length)
* Space: O(1)
*/
class Solution {
    private long sum(int[] array, int start) {
        long result = 0;
        for (int i = start; i < array.length; ++i) {
            result += array[i];
        }
        return result;
    }
    public int pivotIndex(int[] nums) {
        boolean pivotFound = false;
        int pivotIndex;
        long leftSum = 0;
        long rightSum = sum(nums, 1);
        
        for (pivotIndex = 0; pivotIndex < nums.length && !pivotFound; ++pivotIndex) {
            pivotFound = rightSum == leftSum;
            
            if (!pivotFound) {
                leftSum += nums[pivotIndex];
                if (pivotIndex != nums.length - 1) {
                    rightSum -= nums[pivotIndex + 1];
                } else {
                    rightSum = 0;
                }
            }
        }
        
        if (pivotFound) {
            pivotIndex -= 1;
        } else {
            pivotIndex = -1;
        }
        
        return pivotIndex;
    }
}