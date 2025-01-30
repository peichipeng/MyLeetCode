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
    int maxPath = 0;
    pair<int, int> dfs(TreeNode* node) {
        if (!node) return {0, 0};
        pair<int, int> left = dfs(node->left);
        pair<int, int> right = dfs(node->right);
        if (left.second > maxPath) maxPath = left.second;
        if (right.first > maxPath) maxPath = right.first;
        return {left.second + 1, right.first + 1};
    }
    int longestZigZag(TreeNode* root) {
        dfs(root);
        return maxPath;
    }
};