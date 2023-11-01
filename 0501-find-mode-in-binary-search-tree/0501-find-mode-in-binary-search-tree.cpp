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
    unordered_map<int, int>m;
    void solve(TreeNode *root)
    {
        if(root==NULL)
            return;
        m[root->val]++;
        solve(root->left);
        solve(root->right);
        
    }
public:
    vector<int> findMode(TreeNode* root) {
        priority_queue<pair<int,int>>q;
        vector<int> ans;
        
        solve(root);
        
        for(auto it : m)
            q.push({it.second,it.first});
        
        int maxi=q.top().first;
        
        while(q.top().first==maxi && !q.empty())
        {
            ans.push_back(q.top().second);
                q.pop();
        }
        return ans;
            
    }
};