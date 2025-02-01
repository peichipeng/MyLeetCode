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
    vector<pair<TreeNode*, int>> depths;
    void traversal(TreeNode* node, TreeNode* parent, int depth, int x, int y) {
        if (!node) return;
        if (node->val == x || node->val == y) {
            depths.push_back({parent, depth});
        }
        traversal(node->left, node, depth + 1, x, y);
        traversal(node->right, node, depth + 1, x, y);
    }
    bool isCousins(TreeNode* root, int x, int y) {
        traversal(root, NULL, 0, x, y);
        return (depths[0].first != depths[1].first) && (depths[0].second == depths[1].second);
    }
};