#LeetCode link: https://leetcode.com/problems/remove-duplicates-from-sorted-array/

int removeDuplicates(int* nums, int nums_size) {
    int nums_count = 0; //amount of unique elements
    for(int i = 0; i < nums_size; ++i){
        nums[nums_count] = nums[i];
        while(nums[nums_count] == nums[i]) 
            ++i;
        nums_count += 1;
        i -= 1;
    }
    return nums_count;
}