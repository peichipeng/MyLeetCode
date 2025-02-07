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
    int result = 0;
    int rootVal;
    void traversal(TreeNode* node) {
        if (!node) return;
        if (result == 0 && node->val != rootVal) {
            result = node->val;
        } else if (node->val != rootVal) {
            result = min(node->val, result);
        }
        traversal(node->left);
        traversal(node->right);
    }
    int findSecondMinimumValue(TreeNode* root) {
        rootVal = root->val;
        traversal(root);
        return result == 0 ? -1 : result;
    }
};