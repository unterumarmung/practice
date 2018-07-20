//LeetCode Link: https://leetcode.com/problems/move-zeroes/

/*
Complexity analysis:
* Time: O(nums_size)
* Space O(1) 
*/
void moveZeroes(int* nums, int nums_size) {
    int zero_index; //index of first current zero element
    int non_zero_index; //index of current non-zero element
    
    //moving non-zero elements to the beggining of the array
    for (zero_index = 0, non_zero_index = 0; non_zero_index < nums_size; ++non_zero_index) {
        if (nums[non_zero_index] != 0) {
            nums[zero_index] = nums[non_zero_index];
            zero_index += 1;
        }
    }
    
    //adding zero elements to the end
    for (int zero = zero_index; zero < nums_size; ++zero) {
        nums[zero] = 0;
    }
}