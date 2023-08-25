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
    void solve(TreeNode*root,TreeNode*&prev,TreeNode*&first,TreeNode*&middle,TreeNode*&last)
    {
        if(root==NULL)
            return;
        
        solve(root->left,prev,first,middle,last);
        if(prev!=NULL && prev->val>root->val)
        {
            if(first==NULL)
            {
                first=prev;
                middle=root;
            }
            else
            {
                last=root;
            }
        }
        prev=root;
         solve(root->right,prev,first,middle,last);
    }
public:
    void recoverTree(TreeNode* root) {
        TreeNode *prev=new TreeNode(INT_MIN);
        TreeNode *first=NULL;
        TreeNode *middle=NULL;
        TreeNode *last=NULL;
        
        solve(root,prev,first,middle,last);
        
        if(first && last)
        {
            swap(first->val,last->val);
        }
        else if(first && middle)
        {
            swap(first->val,middle->val);
        }
    }
};