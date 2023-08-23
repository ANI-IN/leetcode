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
    int widthOfBinaryTree(TreeNode* root) {
        queue<pair<TreeNode *,int>>q;
        q.push({root,0});
        
        int ans=0;
        while(!q.empty())
        {
            int mini=q.front().second;
            int n=q.size();
            
            int start,last;
            
            for(int i=0;i<n;i++)
            {   
                auto it = q.front();
                long int index=q.front().second-mini;
                TreeNode *node=it.first;
                q.pop();
                
                if(i==0)
                    start=index;
                if(i==n-1)
                    last=index;
                
                if(node->left)
                    q.push({node->left,2*index+1});
                if(node->right)
                    q.push({node->right,2*index+2});
                
            }
            
            ans=max(ans,last-start+1);
        }
        return ans;
    }
};