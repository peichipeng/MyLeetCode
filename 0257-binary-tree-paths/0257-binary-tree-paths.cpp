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
    vector<int> path;
    vector<string> result;
    void traversal(TreeNode* node) {
        if (!node->left && !node->right) {
            string sPath;
            for (int i = 0; i < path.size() - 1; i++) {
                sPath += to_string(path[i]);
                sPath += "->";
            }
            sPath += to_string(path[path.size() - 1]);
            result.push_back(sPath);
            return;
        }
        if (node->left) {
            path.push_back(node->left->val);
            traversal(node->left);
            path.pop_back();
        }
        if (node->right) {
            path.push_back(node->right->val);
            traversal(node->right);
            path.pop_back();
        }
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        if (!root) return result;
        path.push_back(root->val);
        traversal(root);
        return result;
    }
};