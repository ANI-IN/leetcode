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
        int len=0;
        ListNode *temp=head;
        
        if(head->next==NULL && n==1)
            return NULL;
        
        
        
        while(temp!=NULL)
        {
            len++;
            temp=temp->next;
        }
        
        int m=len-n;
        cout<<len<<endl;
        cout<<m<<endl;
        
        temp=head;
        
        if(len==n)
            return head->next;
        
        while(m!=1 && temp!=NULL && temp->next!=NULL)
        {
            
            cout<<temp->val;
            temp=temp->next;
            m--;
            
        }
        
        if(temp->next!=NULL)
        temp->next=temp->next->next;
        return head;
    }
};