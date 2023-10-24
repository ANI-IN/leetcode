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
    void solve(TreeNode *root, int depth, unordered_map<int,int> &m)
    {
        if(root==NULL)
            return ;
        
        if(m.find(depth)==m.end())
        {
            m[depth]=root->val;   
        }
        else
        {
            m[depth]=max(m[depth],root->val);
        }
        solve(root->left,depth+1,m);
        solve(root->right,depth+1,m);
    }
public:
    vector<int> largestValues(TreeNode* root) {
        unordered_map<int,int> m;
        solve(root,0,m);
        
        
        int n=m.size();
        vector<int> ans;
        for(int i=0;i<n;i++)
        {
            int x=m[i];
            ans.push_back(x);
        }
        return ans;
            
    }
};