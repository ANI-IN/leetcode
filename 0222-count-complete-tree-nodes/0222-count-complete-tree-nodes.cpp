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
    int countNodes(TreeNode* root) {
        if(root==NULL)
            return 0;
        
        int lh=solvelh(root);
        int rh=solverh(root);
        
        if(lh==rh)
            return pow(2,lh)-1;
        
        return 1+ countNodes(root->left) + countNodes(root->right);
    }
    
    int solvelh(TreeNode * root)
    {
        int h=0;
        while(root)
        {
            h++;
            root=root->left;
        }
        return h;
    }
    
     int solverh(TreeNode * root)
    {
        int h=0;
        while(root)
        {
            h++;
            root=root->right;
        }
        return h;
    }
};