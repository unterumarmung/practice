#LeetCode Link: https://leetcode.com/problems/merge-two-sorted-lists/
class Solution:
    def min_node(self, node1, node2):
        if min(node1.val, node2.val) == node1.val:
            return node1
        else:
            return node2
    
    def mergeTwoLists(self, l1, l2):
        """
        :type l1: ListNode
        :type l2: ListNode
        :rtype: ListNode
        """
        if l1 is None:
            return l2
        if l2 is None:
            return l1
        
        
        head = self.min_node(l1, l2)
        nodes = []
        
        current1 = l1
        current2 = l2
        
        while current1 is not None or current2 is not None:
                
            if current1 is None:
                nodes.append(current2)
                current2 = current2.next
                
            elif current2 is None:
                nodes.append(current1)
                current1 = current1.next
            else:
                if self.min_node(current1, current2) is current1:
                    nodes.append(current1)
                    current1 = current1.next
                else:
                    nodes.append(current2)
                    current2 = current2.next
            
        for node_index in range(len(nodes) - 1):
            nodes[node_index].next = nodes[node_index + 1]
        
        nodes[-1].next = None
        
        return nodes[0]
        