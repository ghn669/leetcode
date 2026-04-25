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
    ListNode *detectCycle(ListNode *head) {
        ListNode* slow,*fast,*res;
        slow=head;
        fast=head;
        res=head;
        while(fast!=nullptr)
        {
            slow = slow->next;
            if(fast->next==nullptr) return nullptr;
            fast = fast->next->next;
            if(fast==slow)
            {
                while(res!=slow)
                {
                    slow = slow->next;
                    res = res->next;
                }
                return res;
            }
        }
        return nullptr;
    }
};