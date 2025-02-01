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
    TreeNode* pre = NULL;
    int minDiff = INT_MAX;
    void traversal(TreeNode* node) {
        if (!node) return;
        traversal(node->left);
        if (pre) minDiff = min(node->val - pre->val, minDiff);
        pre = node;
        traversal(node->right);
    }
    int getMinimumDifference(TreeNode* root) {
        traversal(root);
        return minDiff;
    }
};