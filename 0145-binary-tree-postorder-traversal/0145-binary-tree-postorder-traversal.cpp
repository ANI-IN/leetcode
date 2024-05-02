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
    vector<int> postorderTraversal(TreeNode* root) {
        stack<pair<TreeNode*,int>> st;
        st.push({root,1});
        vector<int> ans;
        
        if(root==NULL)
            return ans;
        while(!st.empty())
        {
            auto it = st.top();
            if(it.second==1)
            {
                
                st.pop();
                it.second++;
                
                st.push(it);
                
                if(it.first->left)
                    st.push({it.first->left,1});
            }
            else if(it.second==2)
            {
                
                st.pop();
                it.second++;
                
                st.push(it);
                
                if(it.first->right)
                    st.push({it.first->right,1});
            }
            else if(it.second==3)
            {
                ans.push_back(it.first->val);
                st.pop();
            }
        }
        return ans;
        
    }
};