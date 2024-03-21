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
    ListNode* reverseList(ListNode* head) {
       
        
    ListNode *temp=NULL;
       ListNode *x=head;
        
        
        while(x!=NULL)
        {
            ListNode *curr=x->next;
            x->next=temp;
            temp=x;
            x=curr;
        }
        return temp;
    }
};