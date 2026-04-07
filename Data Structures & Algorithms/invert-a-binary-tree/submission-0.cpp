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
    TreeNode* invertTree(TreeNode* root) {
        if (!root) return nullptr;
        queue<TreeNode*> todo;
        todo.push(root);

        while (todo.size() != 0) {
            TreeNode* curr = todo.front();
            todo.pop();
            TreeNode* temp = curr->right;
            curr->right = curr->left;
            curr->left = temp;

            if (curr->left) todo.push(curr->left);
            if (curr->right) todo.push(curr->right);
        }
        return root;
    }
};
