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
    int solve(TreeNode *curr, TreeNode *parent)
    {
        if(curr==NULL)
            return 0;
        
        if(curr->left==NULL && curr->right==NULL)
        {
            if(parent!=NULL && parent->left==curr)
                return curr->val;
        }
        int l=solve(curr->left,curr);
        int r=solve(curr->right,curr);
        
        return l+r;
    }
public:
    int sumOfLeftLeaves(TreeNode* root) {
        return solve(root,NULL);
    }
};