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
    vector<vector<int>> verticalOrder(TreeNode* root) {
        map<int, vector<int>> map;
        queue<pair<TreeNode*, int>> que;
        if (root) que.push({root, 0});
        while (!que.empty()) {
            pair<TreeNode*, int> node = que.front();
            que.pop();

            // node.second = col, node.first->val = value of the node
            map[node.second].push_back(node.first->val);

            if (node.first->left) {
                que.push({node.first->left, node.second - 1});
            }
            if (node.first->right) {
                que.push({node.first->right, node.second + 1});
            }
        }
        vector<vector<int>> result;
        for (auto& vec : map) {
            result.push_back(vec.second);
        }
        return result;
    }
};