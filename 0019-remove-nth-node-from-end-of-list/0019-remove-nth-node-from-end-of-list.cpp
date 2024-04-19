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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *curr=head;
        
        int len=0;
        while(curr!=NULL)
        {
            len++;
            curr=curr->next;
        }
        
        int m=len-n;
        
        if(len==n)
            return head->next;
        
        curr=head;
        while(m!=1 && curr!=NULL && curr->next!=NULL)
        {
            m--;
            curr=curr->next;
        }
        
        if(curr->next!=NULL)
        curr->next=curr->next->next;
        return head;
    }
};