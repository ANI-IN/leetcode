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
        ListNode *curr=head;
        
        while(curr!=NULL)
        {
            ListNode *node=curr->next;
            curr->next=temp;
            temp=curr;
            curr=node;
            
        }
        return temp;
        
   
    }
};