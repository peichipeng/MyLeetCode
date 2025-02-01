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
    TreeNode* first = NULL;
    TreeNode* second = NULL;
    bool swapped = false;
    void traversal(TreeNode* node) {
        if (!node) return;

        traversal(node->left);

        if (pre && !first && node->val < pre->val) {
            first = pre;
            second = node;
        } else if (first && node->val < pre->val) {
            int tmp = first->val;
            first->val = node->val;
            node->val = tmp;
            swapped = true;
        }
        pre = node;

        traversal(node->right);
    }
    void recoverTree(TreeNode* root) {
        traversal(root);
        if (!swapped) {
            int tmp = second->val;
            second->val = first->val;
            first->val = tmp;
        }
    }
};