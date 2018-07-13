//LeetCode Link: https://leetcode.com/problems/delete-node-in-a-linked-list/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
void deleteNode(struct ListNode* node) {
    struct ListNode* temp_node = node->next;
    
    node->val = temp_node->val;
    node->next = temp_node->next;
    
    free(temp_node);
}