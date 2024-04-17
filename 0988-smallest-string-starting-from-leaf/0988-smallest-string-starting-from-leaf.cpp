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
    void solve(TreeNode *root, string curr, string&ans)
    {
        if(root==NULL)
            return;
        
        curr=char(root->val+'a')+curr;
        if(root->left==NULL && root->right==NULL)
        {
            if(ans=="" || ans > curr )
                ans=curr;
        }
        
        solve(root->left,curr,ans);
        solve(root->right,curr,ans);
        
    }
    
    public:
    string smallestFromLeaf(TreeNode* root) {
        
    
        string ans="";
         
        solve(root,"",ans);
        return ans;
    }
};