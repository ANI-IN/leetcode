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
    int solve1(TreeNode *root, int &count)
    {
        if(root==NULL)
            return 0;
        
        count++;
        int l=solve1(root->left,count);
        int r=solve1(root->right,count);
        
        return l+r+root->val;
    }
    void solve(TreeNode *root, int &c)
    {
        if(root==NULL)
            return;
        
        int count=0;
        int sum=solve1(root,count);
        if(sum/count==root->val)
            c++;
        
        solve(root->left,c);
        solve(root->right,c);
    }
public:
    int averageOfSubtree(TreeNode* root) {
        
        int c=0;
        solve(root,c);
        return c;
    }
};