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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (!root) return {};

        queue<pair<TreeNode*,int>> todo;
        todo.push({root,0}); //with level-info
        vector<int> level_list;
        vector<vector<int>> result;
        int prev_level = 0;
        while (!todo.empty()) {
            pair<TreeNode*,int> curr = todo.front();
            todo.pop();
            if (!curr.first) continue;
            
            if (prev_level == curr.second) {
                level_list.push_back(curr.first->val);
            } else {
                //first update, then store
                result.push_back(level_list);
                level_list.clear();
                level_list.push_back(curr.first->val);
                prev_level = curr.second;
            }

            todo.push({curr.first->left, curr.second+1});
            todo.push({curr.first->right, curr.second+1});
        }

        if (!level_list.empty()) result.push_back(level_list);
        return result;
    }
};
