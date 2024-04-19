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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *x=headA;
        ListNode *y=headB;
        
        int l1=0,l2=0;
        
        while(x!=NULL)
        {
            l1++;
            x=x->next;
        }
        
        while(y!=NULL)
        {
            l2++;
            y=y->next;
        }
        
        int diff=abs(l1-l2);
        
        x=headA;
        y=headB;
        if(l1>l2)
        {
            x=headA;
            while(diff--)
            {
                x=x->next;
            }
        }
        else
        {
            y=headB;
            while(diff--)
            {
                y=y->next;
            }
        }
        
        
        while(x!=NULL && y!=NULL)
        {
            if(x==y)
                return x;
            
            x=x->next;
            y=y->next;
        }
        
        return NULL;
    }
};