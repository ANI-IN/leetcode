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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        ListNode *curr = head;
        
        int len = 0;
        while (curr) {
            len++;
            curr = curr->next;
        }
        
        vector<ListNode*> ans(k, nullptr); // Initialize with k nullptrs
        curr = head;
        
        int batch = len / k;
        int extra = len % k;
        ListNode *prev = nullptr;
        
        for (int i = 0; curr != nullptr && i < k; i++) {
            ans[i] = curr;
            
            for (int cnt = 0; cnt < batch + (extra > 0 ? 1 : 0); cnt++) {
                prev = curr;
                curr = curr->next;
            }
            
            if (prev) {
                prev->next = nullptr;
            }
            
            extra--;
        }
        
        return ans;
    }
};
