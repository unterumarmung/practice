#LeetCode link: https://leetcode.com/problems/search-insert-position/

class Solution:
    def searchInsert(self, nums, target):
        
	for index, num in enumerate(nums):
            if num >= target:
                return index
        
        return(len(nums)) 