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
        vector<int> ans;
        stack<TreeNode *> st;
        stack<TreeNode *> st1;
        st.push(root);
        
        if(root==NULL)
            return ans;
        
        while(!st.empty())
        {   
            
            TreeNode *curr=st.top();
            st.pop();
            
            st1.push(curr);
            
            if(curr->left)
                st.push(curr->left);
            if(curr->right)
                st.push(curr->right);
            
        }
        
        while(!st1.empty())
        {
            ans.push_back(st1.top()->val);
            st1.pop();
        }
        return ans;
    }
};