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
    int maxi=-1;
    void solve(TreeNode *root, TreeNode *child)
    {
        if(root==NULL || child==NULL)
            return ;
        maxi=max(maxi,abs(root->val-child->val));
        
        solve(root,child->left);
        solve(root,child->right);
    }
    
    void solve2(TreeNode *root)
    {
        if(root==NULL)
            return ;
        
        solve(root,root->left);
        solve(root,root->right);
        
        solve2(root->left);
        solve2(root->right);
    }
public:
    int maxAncestorDiff(TreeNode* root) {
        
        solve2(root);
        return maxi;
        
    }
};