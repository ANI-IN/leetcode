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
    int solve(TreeNode *root)
    {
        if(root==NULL)
            return 0;
        
        int l=solve(root->left);
        int r=solve(root->right);
        
        return 1+max(l,r);
        
    }
public:
    bool isBalanced(TreeNode* root) {
        if(root==NULL)
            return true;
        
        int l=solve(root->left);
        int r=solve(root->right);
        
        if(abs(l-r)<=1 && isBalanced(root->left) && isBalanced(root->right))
            return true;
        
        return false;
    }
};