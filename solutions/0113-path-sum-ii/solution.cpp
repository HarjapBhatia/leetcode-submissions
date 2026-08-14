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
    vector<vector<int>> res;
    void fn(vector<int> &temp, TreeNode* root, int tg){
        if(!root) return;
        tg -= root->val;
        temp.push_back(root->val);
        if(!tg && !root->left && !root->right){
            res.push_back(temp);
        }
        fn(temp, root->left, tg);
        fn(temp, root->right, tg);
        temp.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int> temp;
        // vector<vector<int>> res;
        fn(temp, root, targetSum);
        return res;
    }
};
