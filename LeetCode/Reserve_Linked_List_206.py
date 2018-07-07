# LeetCode link: https://leetcode.com/problems/reverse-linked-list/

# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def reverseList(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        if head is None: # => length = 0 => there's nothing to rotate
            return None
        
        else: #length = 1 at least
            linked_nodes = list()
            
            current = head
            
            #adding all the nodes to a list
            while current is not None: 
                linked_nodes.append(current)
                current = current.next
            
            linked_nodes = linked_nodes[::-1] #reversing the list
            length = len(linked_nodes)
            
            #changing links to next elements for all the nodes
            for node_index, node in enumerate(linked_nodes):
                if node_index != length - 1: # node is not last one
                    node.next = linked_nodes[node_index + 1]
                else: 
                    node.next = None
            
            return linked_nodes[0]