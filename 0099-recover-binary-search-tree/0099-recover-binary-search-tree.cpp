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
    void solve(TreeNode*root,vector<int>&ans)
    {
        if(root==NULL)
            return;
        solve(root->left,ans);
        ans.push_back(root->val);
        solve(root->right,ans);
    }
    void correctTree(TreeNode* root, const vector<int>& sortedVals, int& index) {
        if (root == nullptr)
            return;

        correctTree(root->left, sortedVals, index);
        if (root->val != sortedVals[index]) {
            root->val = sortedVals[index];
        }
        index++;
        correctTree(root->right, sortedVals, index);
    }
    
    void solve1(TreeNode*root, vector<int>&ans, int &i)
    {
        if(root==NULL)
            return;
        
        solve1(root->left,ans,i);
            if(root->val!=ans[i])
                root->val=ans[i];
        i++;
        solve1(root->right,ans,i);
    }
public:
    void recoverTree(TreeNode* root) {
        vector<int>ans;
        solve(root,ans);
        sort(ans.begin(),ans.end());
        int index=0;
        solve1(root,ans,index);
        
        
        
    }
};