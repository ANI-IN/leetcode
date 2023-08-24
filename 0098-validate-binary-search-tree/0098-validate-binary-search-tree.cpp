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
    void solve(TreeNode *root, vector<int>&res)
    {
        if(root==NULL)
            return;
        solve(root->left,res);
        res.push_back(root->val);
        solve(root->right,res);
    }
public:
    bool isValidBST(TreeNode* root) {
        vector<int> res;
        solve(root,res);
        int n=res.size();
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                if(res[i]>=res[j])
                    return false;
            }
        }
        return true;
    }
};