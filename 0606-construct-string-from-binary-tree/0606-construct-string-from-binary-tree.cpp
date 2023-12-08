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
    void solve(TreeNode *root, string &ans)
    {
        if(root==NULL || (root->left==NULL && root->right==NULL))
            return;
        
        if(root->left==NULL && root->right!=NULL)
            ans+="()";
        
        
        if(root->left){
            ans+="(" +to_string(root->left->val);
            solve(root->left,ans);
            ans.push_back(')');
        }
        
        if(root->right){
            ans+="(" +to_string(root->right->val);
            solve(root->right,ans);
            ans.push_back(')');
        }
        
        return;
        
        
    }
public:
    string tree2str(TreeNode* root) {
        string ans="";
        ans+=to_string(root->val);
        solve(root,ans);
        return ans;
    }
};