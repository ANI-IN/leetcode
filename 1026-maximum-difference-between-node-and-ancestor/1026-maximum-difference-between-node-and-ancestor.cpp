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
    int solve(TreeNode *root, int mini,int maxi)
    {
        if(root==NULL)
        {
            return abs(mini-maxi);
        }
        
        mini=min(mini,root->val);
        maxi=max(maxi,root->val);
        
        int l=solve(root->left,mini,maxi);
        int r=solve(root->right,mini,maxi);
        
        return max(l,r);
    }
public:
    int maxAncestorDiff(TreeNode* root) {
        
        int ans=solve(root,root->val,root->val);
        return ans;
    }
};