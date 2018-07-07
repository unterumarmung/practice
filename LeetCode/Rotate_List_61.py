# LeetCode link: https://leetcode.com/problems/rotate-list/

# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def calc_len(self, head):
        """
        :type head: ListNode
        :rtype: int
        """
        length = 0
        node = head
        while node is not None:
            node = node.next
            length += 1
        return length

    def find_node(self, head, index):
        """
        :type head: ListNode
        :type index: int
        :rtype: ListNode
        """
        found_node = head
        for _ in range(index):
            found_node = found_node.next
        return found_node

    def rotateRight(self, head, k):
        """
        :type head: ListNode
        :type k: int
        :rtype: ListNode
        """
        length = self.calc_len(head)  # O(length) by time, O(1) by space

        if length == 0 or k % length == 0:
            return head

        steps_count = k % length  # leaving only meaningful rotations

        # finding needful nodes
        last = self.find_node(head, length - 1)  # O(length) by time, O(1) by space
        new_last = self.find_node(head, length - steps_count - 1)  # O(length - steps_count) by time, O(1) by space
        new_head = new_last.next

        # changing links
        last.next = head
        new_last.next = None

        return new_head
