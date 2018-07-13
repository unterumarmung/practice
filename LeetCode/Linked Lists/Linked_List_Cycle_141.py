#LeetCode Link: https://leetcode.com/problems/linked-list-cycle/

# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def hasCycle(self, head):
        """
        :type head: ListNode
        :rtype: bool
        """
        if head is None: return False
        
        first_pointer = head
        second_pointer = head.next
        
        while first_pointer != None and second_pointer != None:
            if first_pointer is second_pointer:
                return True
            
            if first_pointer != None and second_pointer.next != None:
                first_pointer = first_pointer.next
                second_pointer = second_pointer.next.next
            else:
                return False
        
        return False