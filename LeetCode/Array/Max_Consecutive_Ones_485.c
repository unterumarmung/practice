//LeetCode Link: https://leetcode.com/problems/max-consecutive-ones/

/*
Complexity analysis:
* Time: O(nums_size)
* Space: O(1)
*/
int findMaxConsecutiveOnes(int* nums, int nums_size) {
    int max_consecutive = 0;
    int current_consecutive = 0;
    bool last_was_one = false;
    
    for (int i = 0; i < nums_size; ++i) {
        if (nums[i] == 1 && !last_was_one) {
            current_consecutive = 1;
            last_was_one = true;
        } 
        else if (nums[i] == 1 && last_was_one) {
            current_consecutive += 1;
        }
        else {
            current_consecutive = 0;
            last_was_one = false;
        }
        
        if (current_consecutive > max_consecutive) 
            max_consecutive = current_consecutive;
    }
    
    return max_consecutive;
}