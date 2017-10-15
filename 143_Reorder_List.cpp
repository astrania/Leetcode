/*
Given a singly linked list L: L0→L1→…→Ln-1→Ln,
reorder it to: L0→Ln→L1→Ln-1→L2→Ln-2→…

You must do this in-place without altering the nodes' values.

For example,
Given {1,2,3,4}, reorder it to {1,4,2,3}. 
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 
class Solution {
public:
    void reorderList(ListNode *head) {
        if (!head || !head->next || !head->next->next) return;
        
        ListNode *fast = head;
        ListNode *slow = head;
        
        while (fast->next && fast->next>next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        ListNode *mid = slow->next;
        slow->next = NULL;
        
        ListNode *last = mid;
        ListNode *pre = NULL;
        
        while (last) {
            ListNode *next = last->next;
            last->next = pre;
            pre = last;
            last = next;
        }
        
        while (head && pre) {
            ListNode *next = head->next;
            head->next = pre;
            pre = pre->next;
            head->next->next = next;
            head = next;
        }
    }
};
            
