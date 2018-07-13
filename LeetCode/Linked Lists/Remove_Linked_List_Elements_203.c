//LeetCode Link: https://leetcode.com/problems/remove-linked-list-elements/

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

struct ListNode* removeElements(struct ListNode* head, int target) {
    if (head == NULL) {
        return NULL;
    }
    else if (head->next == NULL && head->val == target) {
        return NULL;
    }
    else if (head->next == NULL && head->val != target) {
        return head;
    }
    
    struct ListNode* last_node = head;
    struct ListNode* current_node = head->next;
    
    while (current_node != NULL) {
        
        if (current_node->val == target) {
            delete_node(last_node);
            current_node = last_node;
        }
        
        last_node = current_node; 
        current_node = current_node->next;
    }
    
    if (head->val == target) {
        struct ListNode* temp = head;
        head = temp->next;
        free(temp);
    }
    
    return head;
}