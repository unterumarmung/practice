#LeetCode Link: https://leetcode.com/problems/find-all-duplicates-in-an-array/


'''
1st solution
Complexity analysis:
* Time: O(N)
* Space: O(N)
'''
class Solution:
    def findDuplicates(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        nums_length = len(nums)
        appear_times = [0 for _ in range(nums_length + 1)]
        result_list = []
        
        for num in nums:
            appear_times[num] += 1
        
        for num, num_appear in enumerate(appear_times):
            if num_appear == 2:
                result_list.append(num)
                
        return result_list

'''
2nd solution
Complexity analysis:
* Time: ???
* Space: ???
'''
class Solution:
    def findDuplicates(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        nums_length = len(nums)
        transition_set = set()
        result_list = []
        
        for num in nums:
            if num not in transition_set:
                transition_set.add(num)
            else:
                result_list.append(num)
                
        return result_list

'''
3rd solution
Complexity analysis:
* Time: O(N)
* Space: O(1)
'''
class Solution:
    def findDuplicates(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        hash_term = len(nums) + 1
        result_list = []
        
        for i in range(hash_term - 1):
            current_num = nums[i]
            
            if current_num > hash_term: 
                current_num -= hash_term
            
            if nums[current_num - 1] < hash_term:
                nums[current_num - 1] += hash_term
            else:
                result_list.append(current_num)
                
        return result_list
