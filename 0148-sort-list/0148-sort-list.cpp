
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
    
    ListNode *merge(ListNode *left, ListNode *right)
    {
        if(left==NULL)
            return right;
        if(right==NULL)
            return left;
        
        ListNode *ans=new ListNode(-1);
        ListNode *temp=ans;
        
        while(left!=NULL && right!=NULL)
        {
            if(left->val < right->val)
            {
                temp->next=left;
                temp=temp->next;
                left=left->next;
            }
            else
            {
                temp->next=right;
                temp=temp->next;
                right=right->next;
            }
        }
        
        while(left!=NULL)
        {
            temp->next=left;
            temp=temp->next;
            left=left->next;
        }
        
        while(right!=NULL)
        {
            temp->next=right;
            temp=temp->next;
            right=right->next;
        }
        
        return ans->next;
        
    }
        
    
    ListNode *findmid(ListNode *head)
    {
        ListNode *slow=head;
        ListNode *fast=head->next;
        
        while(fast!=NULL && fast->next!=NULL)
        {
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow;
    }
public:
    ListNode* sortList(ListNode* head) {
       if(head==NULL || head->next==NULL)
           return head;
        
        ListNode *mid=findmid(head);
        ListNode *left=head;
        ListNode *right=mid->next;
        mid->next=NULL;
        
        left=sortList(left);
        right=sortList(right);
        
        ListNode *ans=merge(left,right);
        return ans;
    }
};