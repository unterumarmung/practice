#LeetCode Link: https://leetcode.com/problems/merge-sorted-array/

class Solution:
    def merge(self, nums1, m, nums2, n):

        if m == 0 and n == 0:
            pass
        elif m == 0:
            nums1.clear()
            nums1.extend(nums2)
        elif n == 0:
            pass
    
        else:
            current_index_1 = 0
            current_index_2 = 0
            
            for index in range(m + n):
                
                try:
                    current1 = nums1[current_index_1]
                    current2 = nums2[current_index_2]
                except IndexError:
                    break
                
                secondInsert = min(current1, current2) == current2
                firstDone = current1 == 0 and current_index_1 > m + current_index_2 - 1
                
                if secondInsert or firstDone:
                    del nums1[-1]
                    nums1.insert(current_index_1, current2)
                    current_index_1 += 1
                    current_index_2 += 1
                else:
                    current_index_1 += 1