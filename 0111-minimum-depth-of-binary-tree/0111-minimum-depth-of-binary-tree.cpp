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
    int minDepth(TreeNode* root) {
        queue<TreeNode*> que;
        int depth = 0;
        if (!root) return depth;
        que.push(root);
        while (!que.empty()) {
            depth++;
            int size = que.size();
            while (size--) {
                TreeNode* node = que.front();
                que.pop();
                if (node->left == NULL && node->right== NULL) return depth;
                if (node->left) que.push(node->left);
                if (node->right) que.push(node->right);
            }
        }
        return -1;
    }
};