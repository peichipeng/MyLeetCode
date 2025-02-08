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
    void dfs(TreeNode* node, unordered_set<int>& set) {
        if (!node) return;
        set.insert(node->val);
        dfs(node->left, set);
        dfs(node->right, set);
    }

    bool twoSumBSTs(TreeNode* root1, TreeNode* root2, int target) {
        unordered_set<int> set1;
        unordered_set<int> set2;
        dfs(root1, set1);
        dfs(root2, set2);
        for (int num : set1) {
            int numToFind = target - num;
            if (set2.find(numToFind) != set2.end()) return true;
        }
        return false;
    }
};