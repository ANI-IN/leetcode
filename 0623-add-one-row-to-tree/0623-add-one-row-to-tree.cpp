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
    void solve(TreeNode *root, int depth, int val, int count)
    {
        if(root==NULL)
            return;
        if(count==(depth-1))
        {
            TreeNode *temp=new TreeNode (val);
            temp->right=root->right;
            root->right=temp;
            
            temp = new TreeNode (val);
            temp->left=root->left;
            root->left=temp;
            
            return;
        }
        
        solve(root->left,depth,val,count+1);
        solve(root->right,depth,val,count+1);
            
    }
public:
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
       if(depth==1)
       {
           TreeNode *temp=new TreeNode(val);
           temp->left=root;
           return temp;
       }
        
        solve(root,depth,val,1);
        return root;
    }
};