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
class BSTIterator {
    stack<TreeNode*>st;
    bool flag=true;
public:
    
    BSTIterator(TreeNode* root,bool f) {
        flag=f;
        push(root);    
    }
    
    int next() {
        TreeNode* curr=st.top();
        st.pop();
        
        if(!flag)
            push(curr->right);
        else
            push(curr->left);
            
        return curr->val;
    }
    
    bool hasNext() {
        return !st.empty();
    }
    
    void push(TreeNode*root)
    {
        while(root!=NULL)
        {
            st.push(root);
            if(flag==true)
                root=root->right;
            else
                root=root->left;
        }
            
    }
};
class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
       
        if(!root)
        return false;
        
        BSTIterator l(root,false);
        BSTIterator r(root,true);
        
        int i=l.next();
        int j=r.next();
        
        while(i<j)
        {
            if(i+j==k)
                return true;
            else if(i+j<k)
                i=l.next();
            else
                j=r.next();
                
        }
        return false;
    }
};