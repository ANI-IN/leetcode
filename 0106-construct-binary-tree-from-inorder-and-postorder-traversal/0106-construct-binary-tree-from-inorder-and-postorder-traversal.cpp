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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int,int> m;
        int n=inorder.size();
        
        for(int i=0;i<n;i++)
        {
            m[inorder[i]]=i;
        }
        
        TreeNode *root=make(postorder,0,n-1,inorder,0,n-1,m);
        return root;
    }
    TreeNode*make(vector<int>&postorder, int poststart,int postend,vector<int>&inorder,int instart,int inend,unordered_map<int,int>&m)
    {
        if(poststart>postend || instart>inend)
            return nullptr;
        
        TreeNode *root=new TreeNode(postorder[postend]);
        int index=m[root->val];
        int left=index-instart;
        
        root->left = make(postorder, poststart, poststart + left - 1, inorder, instart, index - 1, m);
        root->right = make(postorder, poststart + left, postend - 1, inorder, index + 1, inend, m);
        
      
        return root;
    }
};