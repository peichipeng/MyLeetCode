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
    int goodNodes(TreeNode* root) {
        stack<pair<TreeNode*, int>> st;
        int numGoodNodes = 0;
        if (root) st.push({root, INT_MIN});
        while (!st.empty()) {
            pair<TreeNode*, int> pair = st.top();
            st.pop();
            if (pair.first->val >= pair.second) numGoodNodes++;
            if (pair.first->right) {
                st.push({pair.first->right, max(pair.second, pair.first->val)});
            }
            if (pair.first->left) {
                st.push({pair.first->left, max(pair.second, pair.first->val)});
            }
        }
        return numGoodNodes;
    }
};