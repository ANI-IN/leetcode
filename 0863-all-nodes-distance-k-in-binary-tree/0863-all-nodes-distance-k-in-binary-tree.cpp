/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
    void mark_parent(unordered_map<TreeNode *, TreeNode *> &m, TreeNode* root)
    {
        queue<TreeNode*>q;
        q.push(root);
        
        while(!q.empty())
        {
            TreeNode *node=q.front();
            q.pop();
            
            if(node->left)
            {
                m[node->left]=node;
                q.push(node->left);
            }
            
            if(node->right)
            {
                m[node->right]=node;
                q.push(node->right);
            }
        }
    }
    
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode *, bool> vis;
        unordered_map<TreeNode *, TreeNode *> m;
        vector<int> ans;
        queue<TreeNode*>q;
        
        
        mark_parent(m,root);
        
/*      for(auto it : m)
        {
            cout<<"NODE IS "<<it.first->val<<" PARENT IS "<<it.second->val<<endl;
        }
*/      
        
        q.push(target);
        vis[target]=true;
        int distance=0;
        
        while(!q.empty())
        {
            int n=q.size();
            
            if(distance++==k)
                break;
            
            for(int i=0;i<n;i++)
            {
                TreeNode * node=q.front();
                q.pop();
                
                if(node->left && !vis[node->left])
                {
                    q.push(node->left);
                    vis[node->left]=true;
                }
                
                if(node->right && !vis[node->right])
                {
                    q.push(node->right);
                    vis[node->right]=true;
                }
                
                if(m[node] && !vis[m[node]])
                {
                    q.push(m[node]);
                    vis[m[node]]=true;
                }
            }
        }
        
        
        while(!q.empty())
        {
            TreeNode * node=q.front();
            q.pop();
            ans.push_back(node->val);
        }
        return ans;
        
    }
};