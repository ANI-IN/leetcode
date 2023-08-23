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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        queue<pair <TreeNode*,pair<int,int>> >q;      // <TreeNode <vertical,level>> 
            q.push({root,{0,0}});
        
        map<int,map<int,multiset<int>>> m;
        while(!q.empty())
        {
            auto it = q.front();
            q.pop();
            
            int x=it.second.first;   //vertical
            int y=it.second.second;  //level
            
            m[x][y].insert(it.first->val);
            
            if(it.first->left)
            {
                q.push({it.first->left,{x-1,y+1}});
            }
            if(it.first->right)
            {
                q.push({it.first->right,{x+1,y+1}});
            }
            
        }
        
        vector<vector<int>> ans;
        
        for(auto it : m)
        {   
            vector<int> temp;
            for(auto p : it.second)
            {
                for(auto z : p.second)
                {
                    temp.push_back(z);
                }
            }
            ans.push_back(temp);
        }
        return ans;
    }
};