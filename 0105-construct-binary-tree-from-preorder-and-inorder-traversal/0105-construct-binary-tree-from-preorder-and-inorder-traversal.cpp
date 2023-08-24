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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int,int> m;
        int n=preorder.size();
        
        for(int i=0;i<n;i++)
        {
            m[inorder[i]]=i;
        }
        
        TreeNode *root=make(preorder, 0, n-1, inorder, 0, n-1, m);
        return root;
    }
    
    TreeNode *make(vector<int>&preorder,int prestart, int preend,vector<int>&inorder,int instart,int inend,
                  unordered_map<int,int>&m)
    {
        if(prestart>preend || instart>inend)
            return nullptr;
        
        TreeNode *root=new TreeNode(preorder[prestart]);
        int index=m[root->val];
        int left=index-instart;
        
        root->left=make(preorder,prestart+1,prestart+left,inorder,instart,index-1,m);
        root->right=make(preorder,prestart+left+1,preend,inorder,index+1,inend,m);
        return root;
    }
};