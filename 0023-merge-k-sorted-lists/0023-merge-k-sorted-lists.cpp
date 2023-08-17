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
class comp{
  public:  
    bool operator()(ListNode *a, ListNode *b)
    {
        if(a->val>b->val)
            return true;
        else
            return false;
            
    }
};
class Solution{ 
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode *, vector<ListNode*>,comp>q;
        
        for(int i=0;i<lists.size();i++)
        {
            if(lists[i]!=NULL)
                q.push(lists[i]);
        }
        
        ListNode *head= new ListNode(0);
        ListNode *curr=head;
        
        while(!q.empty())
        {
            ListNode *temp=q.top();
            q.pop();
            curr->next=temp;
            curr=curr->next;
            
            if(temp->next!=NULL)
            {
                q.push(temp->next);
            }
        }
        return head->next;
        
    }
};