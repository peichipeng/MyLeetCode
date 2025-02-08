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
    void traversal(TreeNode* node, vector<int>& result) {
        if (!node) return;
        if (node->left && !node->right) {
            result.push_back(node->left->val);
        }
        if (!node->left && node->right) {
            result.push_back(node->right->val);
        }
        traversal(node->left, result);
        traversal(node->right, result);
    }

    vector<int> getLonelyNodes(TreeNode* root) {
        vector<int> result;
        traversal(root, result);
        return result;
    }
};