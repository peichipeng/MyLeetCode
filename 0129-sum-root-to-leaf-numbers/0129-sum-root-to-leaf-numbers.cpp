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
    int sum = 0;
    void dfs(TreeNode* node, string str) {
        if (!node->left && !node->right) {
            sum += stoi(str);
            return;
        }
        if (node->left) {
            dfs(node->left, str + to_string(node->left->val));
        }
        if (node->right) {
            dfs(node->right, str + to_string(node->right->val));
        }
    }
    int sumNumbers(TreeNode* root) {
        dfs(root, to_string(root->val));
        return sum;
    }
};