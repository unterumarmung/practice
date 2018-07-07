#LeetCode link: https://leetcode.com/problems/remove-duplicates-from-sorted-array/

class Solution:
    def removeDuplicates(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        #new list with deleted dublicates
        new_nums = sorted(list(set(nums)))
        
        new_length = len(new_nums)
        old_length = len(nums)
        
        #copying new array to nums
        for index, num in enumerate(new_nums):
            nums[index] = num
        
        #deteleting old elements
        for _ in range(new_length, old_length):
            del nums[new_length]
        
        return new_length