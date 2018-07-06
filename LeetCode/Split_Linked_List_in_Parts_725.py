#LeetCode link: https://leetcode.com/problems/split-linked-list-in-parts/description/

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

    def splitListToParts(self, root, k):
        """
        :type root: ListNode
        :type k: int
        :rtype: List[ListNode]
        """
        length = self.calc_len(root)
        
        ret_list = [] #returning list
        
        if k > length: #Each part has length <= 1
            cur_node = root
            
            #adding each single node to the list
            for _ in range(length):
                next_node = cur_node.next
                cur_node.next = None
                ret_list.append(cur_node)
                cur_node = next_node
            
            #adding None-objects to the end
            for _ in range(k - length):
                ret_list.append(None)
            
        
        else: #Each part has non-zero length
            
            parts_length = [] #list that contains length of each part
            
            if length % k == 0: #Each part has the equal "sub"-length
                parts_length = [length // k for _ in range(k)]
            
            else: #Some parts are larger than others
                for i in range(k):
                    if i < length % k:
                        parts_length.append(length//k + 1)
                    else:
                        parts_length.append(length // k)
            
            part_root = root #root of a current part
            
            for part_index in range(k):
                
                last_node = self.find_node(part_root, parts_length[part_index] - 1) #last node of a current part
                next_root = last_node.next #root of a next part
                
                last_node.next = None
                ret_list.append(part_root)
                part_root = next_root
            
        
        return ret_list