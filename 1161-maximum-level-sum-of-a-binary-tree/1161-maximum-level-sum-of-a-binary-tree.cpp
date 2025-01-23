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
    int maxLevelSum(TreeNode* root) {
        queue<TreeNode*> que;
        if (root) que.push(root);
        int currentLevel = 1;
        int result = 0;
        int maxSum = INT_MIN;
        while (!que.empty()) {
            int size = que.size();
            int sum = 0;
            while (size--) {
                TreeNode* node = que.front();
                que.pop();
                sum += node->val;
                if (node->left) que.push(node->left);
                if (node->right) que.push(node->right);
            }
            if (sum > maxSum) {
                maxSum = sum;
                result = currentLevel;
            }
            currentLevel++;
        }
        return result;
    }
};