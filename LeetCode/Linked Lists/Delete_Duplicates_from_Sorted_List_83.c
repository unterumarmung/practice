//LeetCode Link: https://leetcode.com/problems/remove-duplicates-from-sorted-list/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
void delete_node(struct ListNode* before_node) {
    struct ListNode* node_to_delete = before_node->next;
    
    if (node_to_delete != NULL) { 
        before_node->next = node_to_delete->next;
        free(node_to_delete);
    }
}

struct ListNode* deleteDuplicates(struct ListNode* head) {
    if (head == NULL) return NULL;
    
    struct ListNode* current_node = head->next;
    struct ListNode* last_node = head;
    int index = 1;
    
    while (current_node != NULL) {
        if (current_node->val == last_node->val) {
            delete_node(last_node);
            current_node = last_node;
        } else {
            last_node = current_node;
        }
        
        current_node = current_node->next;
        index += 1;
    }
    
    return head;
}