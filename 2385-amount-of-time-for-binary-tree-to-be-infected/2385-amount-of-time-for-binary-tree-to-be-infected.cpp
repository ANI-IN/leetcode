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
    void solve(TreeNode *root,  unordered_map<int,vector<int>> &m, int par)
    {
        if(root==NULL)
            return;
        
        
        if(par!=-1)
        {
            m[root->val].push_back(par);
        }
        
        if(root->left)
        {
           m[root->val].push_back(root->left->val);
        }
        
        if(root->right)
        {
            m[root->val].push_back(root->right->val);
        }
        solve(root->left,m,root->val);
        solve(root->right,m,root->val);
        
    }
public:
    int amountOfTime(TreeNode* root, int start) {
        
        unordered_map<int,vector<int>> adj;
        solve(root,adj,-1);
        
        int time=0;
        queue<pair<int,int>> q;     //node time
        q.push({start,0});
        unordered_set<int> st;
        st.insert(start);
        
        int ans=INT_MIN;
        while(!q.empty())
        {
            int node=q.front().first;
            int time=q.front().second;
            q.pop();
            
            ans=max(ans,time);
            
            for(auto it : adj[node])
            {
                if(st.count(it)==0)
                {
                    st.insert(it);
                    q.push({it,time+1});
                }
            }
        }
        return ans;
    }
};