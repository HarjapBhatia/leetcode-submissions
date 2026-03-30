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
typedef long long ll;
class Solution {
public:
    bool fn(TreeNode* root, ll mi, ll mx){
        if(!root) return true;
        if(root->val <=mi || root->val>=mx) return false;
        return fn(root->left, mi, root->val) && fn(root->right, root->val, mx);
    }
    bool isValidBST(TreeNode* root) {
        ll mi = LLONG_MIN, mx = LLONG_MAX;
        return fn(root, mi, mx); 
    }
};
