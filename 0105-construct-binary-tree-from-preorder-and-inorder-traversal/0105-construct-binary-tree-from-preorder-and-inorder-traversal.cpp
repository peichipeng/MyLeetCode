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
    TreeNode* traversal(vector<int>& preorder, int preorderBegin, int preorderEnd, vector<int>& inorder, int inorderBegin, int inorderEnd) {
        if (preorderBegin == preorderEnd) return NULL;

        int rootVal = preorder[preorderBegin];
        TreeNode* root = new TreeNode(rootVal);

        if (preorderEnd - preorderBegin == 1) return root;

        int delimiter;
        for (delimiter = inorderBegin; delimiter < inorderEnd; delimiter++) {
            if (inorder[delimiter] == rootVal) break;
        }

        int leftInorderBegin = inorderBegin;
        int leftInorderEnd = delimiter;
        int rightInorderBegin = delimiter + 1;
        int rightInorderEnd = inorderEnd;

        int leftPreorderBegin = preorderBegin + 1;
        int leftPreorderEnd = leftPreorderBegin + leftInorderEnd - leftInorderBegin;
        int rightPreorderBegin = leftPreorderEnd;
        int rightPreorderEnd = preorderEnd;

        root->left = traversal(preorder, leftPreorderBegin, leftPreorderEnd, inorder, leftInorderBegin, leftInorderEnd);
        root->right = traversal(preorder, rightPreorderBegin, rightPreorderEnd, inorder, rightInorderBegin, rightInorderEnd);
        return root;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return traversal(preorder, 0, preorder.size(), inorder, 0, inorder.size());
    }
};