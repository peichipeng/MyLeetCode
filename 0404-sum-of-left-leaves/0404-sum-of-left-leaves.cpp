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
    int sumOfLeftLeaves(TreeNode* root) {
        if (!root) return 0;
        if (!root->left && !root->right) return 0;
        int leftSum;
        if (root->left && !root->left->left && !root->left->right) {
            leftSum = root->left->val;
        } else {
            leftSum = sumOfLeftLeaves(root->left);
        }
        int rightSum = sumOfLeftLeaves(root->right);
        return leftSum + rightSum;
    }
};