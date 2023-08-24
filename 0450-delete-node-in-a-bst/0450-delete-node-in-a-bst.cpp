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
    TreeNode * solve(TreeNode *root)
    {
        if(root->left==NULL)
            return root->right;
        else if(root->right==NULL)
            return root->left;
        TreeNode *next_right=root->right;
        TreeNode *left_last_right=findlast(root->left);
        left_last_right->right=next_right;
        return root->left;
        
    }
    
    TreeNode *findlast(TreeNode * root)
    {
        if(root->right==NULL)
            return root;
        return findlast(root->right);
    }
    
    
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root==NULL)
            return NULL;
        TreeNode * curr=root;
        
        if(root->val==key)
            return solve(root);
            
        while(root!=NULL)
        {
            if(root->val > key)
            {
                if(root->left!=NULL && root->left->val==key)
                {
                    root->left=solve(root->left);
                    break;
                }
                else
                {
                    root=root->left;
                }
            }
            else
            {
                if(root->right!=NULL && root->right->val==key)
                {
                    root->right=solve(root->right);
                    break;
                }
                else
                {
                    root=root->right;
                }
            }
        }
        return curr;
    }
};