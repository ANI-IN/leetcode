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
    bool hasCycle(ListNode *head) {
        
        if(head==NULL || head->next==NULL)
            return false;
        
        ListNode *curr=head;
        ListNode *fast=head->next;
        
        while(curr!=fast)
        {   
            if(fast==NULL || fast->next==NULL)
                return false;
            curr=curr->next;
            fast=fast->next->next;
        }
        return true;
    }
};