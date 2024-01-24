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
    void solve(TreeNode *root, vector<int>&arr, int &c)
    {
        if(root==NULL)
            return ;
        
        arr[root->val]++;
        if(root->left==NULL && root->right==NULL)
        {
            int odd=0;
            for(int i=1;i<=9;i++)
            {
                if(arr[i]%2!=0)
                    odd++;
            }
            if(odd<=1)
                c++;
        }
        
        solve(root->left,arr,c);
        solve(root->right,arr,c);
        arr[root->val]--;
    }
        
public:
    int pseudoPalindromicPaths (TreeNode* root) {
        
        int result=0;
        vector<int> arr(10,0);
        solve(root,arr,result);
        return result;
    }
};