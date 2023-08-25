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
class bst{
  stack<TreeNode*>st;
  bool flag=true;       //true inorder push all left then check right exits or not
                        // false push all the right then check left exits or not
    public:
        bst(TreeNode*root,bool f)
        {
            flag=f;
            push(root);
        }
    
        int next()
        {
            TreeNode* curr=st.top();
            st.pop();
            
            if(flag==true)
                push(curr->right);
            else
                push(curr->left);
            
            return curr->val;
        }
        
        void push(TreeNode *root)
        {
            while(root!=NULL)
            {
                st.push(root);
                
                if(flag==true)
                {
                    root=root->left;
                }
                else
                {
                    root=root->right;
                }
            }
        }
    
};

class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        bst l(root,true);
        bst r(root,false);
        
        if(root==NULL)
            return false;
        
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