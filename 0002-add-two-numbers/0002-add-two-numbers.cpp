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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *curr=new ListNode(-1);
        ListNode *node=curr;
        
        int sum=0,carry=0;
        while(l1!=NULL || l2!=NULL || carry!=0)
        {
            sum=0;
            if(l1!=NULL)
            {
                sum=sum+l1->val;
                l1=l1->next;
            }
            
            if(l2!=NULL)
            {
                sum=sum+l2->val;
                l2=l2->next;
            }
            
            sum=sum+carry;
            carry=sum/10;
            sum=sum%10;
            
            cout<<sum<<endl;
            
            ListNode *next=new ListNode(sum);
            node->next=next;
            node=node->next;;
        }
        return curr->next;
    }
};