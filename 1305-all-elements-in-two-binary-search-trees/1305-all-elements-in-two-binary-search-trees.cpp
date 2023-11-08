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
    void solve(TreeNode *root, vector<int>&arr)
    {
        if(root==NULL)
            return;
        
        solve(root->left,arr);
        arr.push_back(root->val);
        solve(root->right,arr);
    }
public:
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> a;
        vector<int> b;
        vector<int> ans;
        solve(root1,a);
        solve(root2,b);
        
        int n=a.size();
        int m=b.size();
        
        int i=0,j=0;
        
        while(i<n && j<m)
        {
            if(a[i]<b[j])
            {
                ans.push_back(a[i]);
                i++;
            }
            else
            {
                ans.push_back(b[j]);
                j++;
            }
        }
        
        while(i<n)
        {
            ans.push_back(a[i]);
            i++;
        }
        
        while(j<m)
        {
            ans.push_back(b[j]);
            j++;
        }
        return ans;
    }
};