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
	private:
	int res=0;
public:
	void dfs(TreeNode* root, int L, int R){
		if(not root) return;
		if(root->val>=L && root->val<=R){
			res+=root->val;
		}
		if(root->val<L){
			dfs(root->right,L,R);
		}
		else if(root->val>R){
			dfs(root->left,L,R);
		}
		else{
			 dfs(root->right,L,R);
			dfs(root->left,L,R);
		}
	}
	int rangeSumBST(TreeNode* root, int L, int R) {
	  dfs(root,L,R);
		return res;
	}
};