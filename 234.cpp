//回文链表
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        left = head;
        return reverse(head);
    }

    ListNode* left;

    bool reverse(ListNode* right)
    {
        if(right == nullptr) return true;

        bool res = reverse(right->next);

        res = res && (left->val == right->val);  

        left = left->next;

        return res;
    }
};