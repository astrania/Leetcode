/*
Given a singly linked list, determine if it is a palindrome. 
Follow up: Could you do it in O(n) time and O(1) space?
*/

class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if (!head || !head->next) return true;
        
        ListNode *slow = head;
        ListNode *fast = head;
        stack<int> s;
        s.push(head->val);
        
        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
            s.push(slow->val);
        }
        
        if (!fast->next) s.pop();
        
        while (slow->next) {
            slow = slow->next;
            int tmp = s.top();
            s.pop();
            if (tmp != slow->val) return false;
        }
        return true;
    }
};
        
