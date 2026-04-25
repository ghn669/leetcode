/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* pre = head;
        ListNode* cur = head;
        if(head==nullptr) return head;
        while(cur!=nullptr)
        {
            while(cur!=nullptr&&pre!=nullptr&&pre->val==cur->val)
            {
                cur = cur->next;
            }
            if(pre) pre->next=cur;
            pre=cur;
            if(cur) cur = cur->next;
        }
        return head;
    }
};