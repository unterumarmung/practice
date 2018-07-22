#LeetCode Link: https://leetcode.com/problems/design-linked-list/

class MyLinkedList:
    
    #definition of a node
    class ListNode:
        def __init__(self, value):
            self.val = value
            self.next = None
    
    
    head = None # a reference to the head of the list
    tail = None # a reference to the tail the list to provide O(1) adding to the tail
    length = 0 # a number of nodes
    
    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.head = None
        self.tail = None
        self.length = 0
    
    def find(self, index:int) -> ListNode:
        """
        Find the index-th node and return it
        """
        if index >= 0 and index < self.length:
            node = self.head
            for _ in range(index):
                node = node.next

            return node
        else:
            return None
    
    def get(self, index:int) -> int:
        """
        Get the value of the index-th node in the linked list. If the index is invalid, return -1.
        """
        if index >= 0 and index < self.length:
            return self.find(index).val
        else:
            return -1

    def addAtHead(self, val:int):
        """
        Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list.
        """
        if self.length == 0:
            self.head = self.tail = self.ListNode(val)
        else:
            new_node = self.ListNode(val)
            new_node.next = self.head
            self.head = new_node
        
        self.length += 1

    def addAtTail(self, val:int):
        """
        Append a node of value val to the last element of the linked list.
        """
        if self.length == 0:
            self.tail = self.head = self.ListNode(val)
        else:
            new_node = self.ListNode(val)
            self.tail.next = new_node
            self.tail = new_node
            self.tail.next = None
        
        self.length += 1
        
    def addAtIndex(self, index:int, val:int):
        """
        Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted.
        """
        if index == 0:
            self.addAtHead(val)
        elif index == self.length:
            self.addAtTail(val)
        elif index >= 0 and index < self.length:
            new_node = ListNode(val)
            prev_node = self.find(index - 1)
            next_node = prev_node.next
            
            prev_node.next = new_node
            new_node.next = next_node
            
            self.length += 1 
        else:
            pass

    def deleteAtIndex(self, index:int):
        #print("deleteAtIndex:", index)
        """
        Delete the index-th node in the linked list, if the index is valid.
        """
        
        if index >= 0 and index < self.length:
            if index == 0:
                node_to_delete = head
                head = head.next
                
            elif index == self.length - 1:
                prev_node = self.find(index - 1)
                node_to_delete = prev_node.next
                prev_node.next = None
                self.tail = prev_node
            else:
                prev_node = self.find(index - 1)  
                #print("index = ", index, "\nlength = ", self.length)
                node_to_delete = self.find(index)
                
                node_to_delete = prev_node.next
                prev_node.next = node_to_delete.next
                
            del node_to_delete
            self.length -= 1