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
    void insert(ListNode*curr, ListNode *temp, int gd)
    {
        ListNode *to_be_insert=new ListNode(gd);
        
        to_be_insert->next=temp;
        curr->next=to_be_insert;
    }
        
public:
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        
        ListNode *curr=head;
        ListNode *temp=curr->next;
        
        while(curr!=NULL && temp!=NULL)
        {
            int gd=__gcd(curr->val,temp->val);
            
            insert(curr,temp,gd);
            
            curr=temp;
            temp=temp->next;
        }
        return head;
    }
};