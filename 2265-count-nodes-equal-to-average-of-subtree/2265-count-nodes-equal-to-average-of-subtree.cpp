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
    pair<int,int> solve(TreeNode *root, int &ans)
    {
        if(root==NULL)
            return {0,0};
        
        auto l=solve(root->left,ans);
        auto r=solve(root->right,ans);
        
        int sum=l.first+r.first+root->val;
        int c=l.second+r.second+1;
        
        int avg=(sum/c);
        if(avg==root->val)
            ans++;
        
        return {sum,c};
        
    }
public:
    int averageOfSubtree(TreeNode* root) {
        int ans=0;
        
        auto p=solve(root,ans);
        return ans;
    }
};