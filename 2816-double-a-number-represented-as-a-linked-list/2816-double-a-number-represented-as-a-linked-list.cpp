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
    ListNode* reverse(ListNode *head)
    {
        ListNode *curr=head;
        ListNode *next=NULL;
        ListNode *prev=NULL;
        
        while(curr!=NULL)
        {
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        return prev;
    }
    
public:
    ListNode* doubleIt(ListNode* head) {
        int carry=0,sum=0;
        
        ListNode *rev=reverse(head);
        ListNode *curr=rev;
        ListNode *prev=NULL;
        
        while(curr!=NULL)
        {
            int v=curr->val;
            int sum=2*v+carry;
            carry=sum/10;
            v=sum%10;
            
            curr->val=v;
            prev=curr;
            curr=curr->next;
        }
        if(carry>0)
            prev->next=new ListNode(carry);
        return reverse(rev);
    }
};