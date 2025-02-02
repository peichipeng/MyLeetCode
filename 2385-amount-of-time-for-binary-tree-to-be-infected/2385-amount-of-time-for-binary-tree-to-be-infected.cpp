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
    void convert(TreeNode* current, int parent, unordered_map<int, unordered_set<int>>& map) {
        // Automatically creates an empty unordered_set<int>
        unordered_set<int>& adjList = map[current->val];

        if (parent != 0) {
            adjList.insert(parent);
        }
        if (current->left) {
            adjList.insert(current->left->val);
            convert(current->left, current->val, map);
        }
        if (current->right) {
            adjList.insert(current->right->val);
            convert(current->right, current->val, map);
        }
    }
    int amountOfTime(TreeNode* root, int start) {
        unordered_map<int, unordered_set<int>> map;
        convert(root, 0, map);
        queue<int> que;
        que.push(start);
        int minute = 0;
        unordered_set<int> visited;
        visited.insert(start);

        while (!que.empty()) {
            int levelSize = que.size();
            while (levelSize > 0) {
                int current = que.front();
                que.pop();

                for (int num : map[current]) {
                    if (visited.find(num) == visited.end()) {
                        visited.insert(num);
                        que.push(num);
                    }
                }
                levelSize--;
            }
            minute++;
        }
        return minute - 1;
    }
};