/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> largestValues(TreeNode* root) {
        vector<int> ans;
        queue<TreeNode*>q;
        
         if (root == nullptr) {
            return ans;
        }
        
        q.push(root);
        while(!q.empty())
        {
            int size=q.size();
            int maxi=INT_MIN;
            for(int i=0;i<size;i++)
            {
               TreeNode* no=q.front();
                q.pop();
                maxi=max(maxi,no->val);
                if(no->left)
                    q.push(no->left);
                if(no->right)
                    q.push(no->right);
            }
            ans.push_back(maxi);
        }
        return ans;
    }
};