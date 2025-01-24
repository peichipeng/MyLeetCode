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
    int result;
    void getDepth(TreeNode* node, int depth) {
        result = depth > result ? depth : result;
        if (node->left == NULL && node->right == NULL) return;
        if (node->left) {
            getDepth(node->left, depth + 1);
        }
        if (node->right) {
            getDepth(node->right, depth + 1);
        }
    }
    int maxDepth(TreeNode* root) {
        result = 0;
        if (!root) return result;
        getDepth(root, 1);
        return result;
    }
};