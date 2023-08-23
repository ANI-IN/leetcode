/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
    bool solve(TreeNode* root, vector<TreeNode*>& ans, TreeNode* b) {
        if (root == NULL)
            return false;
        
        ans.push_back(root);
        
        if (root->val == b->val)
            return true;
        
        if (solve(root->left, ans, b) || solve(root->right, ans, b))
            return true;
        
        ans.pop_back();
        return false;
    }
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        
        vector<TreeNode *>pp;
        vector<TreeNode *>qq;
        
        
        solve(root,pp,p);
        solve(root,qq,q);
        
        TreeNode *prev=NULL;
        
        int n=min(pp.size(),qq.size());
        
        for(int i=0;i<n;i++)
        {
            if(pp[i]->val==qq[i]->val)
                prev=pp[i];
            else
                break;
        }
        return prev;
    }
};