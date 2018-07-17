#LeetCode Link: https://leetcode.com/problems/range-sum-query-immutable/

class NumArray:
    sum_array = []
    
    def __init__(self, nums):
        """
        :type nums: List[int]
        """
        self.sum_array = []
        
        size = len(nums)
        
        if size > 0:
            self.sum_array.append(nums[0])
            for i in range(1, size):
                self.sum_array.append(nums[i] + self.sum_array[i - 1])
        print(self.sum_array)
        

    def sumRange(self, i, j):
        """
        :type i: int
        :type j: int
        :rtype: int
        """
        if i == 0: return self.sum_array[j]
        else: return self.sum_array[j] - self.sum_array[i - 1]