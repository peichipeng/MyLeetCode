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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        queue<pair<TreeNode*, pair<int, int>>> que;
        que.push({root, {0, 0}});
        vector<vector<int>> nodes;
        while (!que.empty()) {
            pair<TreeNode*, pair<int, int>> node = que.front();
            que.pop();
            nodes.push_back({node.first->val, node.second.first, node.second.second});

            if (node.first->left) {
                que.push({node.first->left, {node.second.first + 1, node.second.second - 1}});
            }
            if (node.first->right) {
                que.push({node.first->right, {node.second.first + 1, node.second.second + 1}});
            }
        }
        sort(nodes.begin(), nodes.end(), [](vector<int>& a, vector<int>& b) {
            if (a[1] != b[1]) return a[1] < b[1];
            if (a[2] != b[2]) return a[2] < b[2];
            return a[0] < b[0];
        });

        map<int, vector<int>> colMap;
        for (const auto& node : nodes) {
            colMap[node[2]].push_back(node[0]);
        }

        vector<vector<int>> result;
        for (const auto& [col, vals] : colMap) {
            result.push_back(vals);
        }
        return result;
    }
};