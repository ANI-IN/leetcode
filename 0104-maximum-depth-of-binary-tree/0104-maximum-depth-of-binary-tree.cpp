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
    int maxDepth(TreeNode* root) {
        if (!root) {
            return 0; // Base case: empty tree has depth 0
        }
        
        queue<TreeNode*> q;
        q.push(root);

        int ans = 0;

        while (!q.empty()) {
            int n = q.size();
            for (int i = 0; i < n; i++) {
                auto it = q.front();
                q.pop();

                if (it->left) {
                    q.push(it->left);
                }
                if (it->right) {
                    q.push(it->right);
                }
            }
            ans++;
        }
        return ans;
    }
};