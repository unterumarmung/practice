#LeetCode Link: https://leetcode.com/problems/array-partition-i/
class Solution:
    def arrayPairSum(self, nums):
        #sum every "second" (0, 2, 4, ..., n) in sorted(nums)
        return sum(sorted(nums)[::2])