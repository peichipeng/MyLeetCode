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
    bool checkPalindrome(unordered_map<int, int>& freq) {
        bool oddFreq = false;
        for (auto [num, count] : freq) {
            if (count % 2 == 1) {
                if (oddFreq) return false;
                oddFreq = true;
            }
        }
        return true;
    }
    void dfs(TreeNode* node, unordered_map<int, int>& freq, int& count) {
        freq[node->val]++;
        if (!node->left && !node->right) {
            count += checkPalindrome(freq);
            return;
        }
        if (node->left) {
            dfs(node->left, freq, count);
            freq[node->left->val]--;
            if (freq[node->left->val] == 0) freq.erase(node->left->val);
        }
        if (node->right) {
            dfs(node->right, freq, count);
            freq[node->right->val]--;
            if (freq[node->right->val] == 0) freq.erase(node->right->val);
        }
    }
    int pseudoPalindromicPaths (TreeNode* root) {
        int count = 0;
        unordered_map<int, int> freq;
        dfs(root, freq, count);
        return count;
    }
};