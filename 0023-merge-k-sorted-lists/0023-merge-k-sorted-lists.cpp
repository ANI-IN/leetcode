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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<int,vector<int>,greater<int>>q;
        
        for(int i=0;i<lists.size();i++)
        {
            ListNode *curr=lists[i];
            while(curr!=NULL)
            {
                q.push(curr->val);
                curr=curr->next;
            }
        }
        
       ListNode* dummy = new ListNode(); // Create a dummy node to simplify list operations
        ListNode* curr = dummy; // Use a pointer to iterate through the merged list
        
        while(!q.empty()) {
            curr->next = new ListNode(q.top());
            q.pop();
            curr = curr->next;
        }
        
        return dummy->next;
    }
};