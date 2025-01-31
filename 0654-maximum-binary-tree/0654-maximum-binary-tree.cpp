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
private:
    TreeNode* traversal(vector<int>& nums, int left, int right) {
        if (left >= right) return NULL;

        int maxValIndex = left;
        for (int i = left + 1; i < right; i++) {
            if (nums[i] > nums[maxValIndex]) maxValIndex = i;
        }

        TreeNode* root = new TreeNode(nums[maxValIndex]);

        root->left = traversal(nums, left, maxValIndex);
        root->right = traversal(nums, maxValIndex + 1, right);
        return root;
    }
public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return traversal(nums, 0, nums.size());
    }
};