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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        queue<TreeNode*>q;
        q.push(root);
        bool flag=1;
        if(root==NULL)
            return ans;
        
        while(!q.empty())
        {
            int n=q.size();
            vector<int> temp(n);
                
            for(int i=0;i<n;i++)
            {
                auto it=q.front();
                q.pop();
                if(flag)
                {
                    temp[i]=it->val;
                }
                else
                {
                    temp[n-i-1]=it->val;
                }
                
                if(it->left)
                    q.push(it->left);
                if(it->right)
                    q.push(it->right);
                
            }
            ans.push_back(temp);
            flag=!flag;
        }
        return ans;
        
    }
};