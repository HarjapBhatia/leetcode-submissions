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
    int ansheight=0, ans=0;
    void f(TreeNode* root, int h){
        if(!root) return;
        f(root->left, h+1);
        if(h > ansheight){
            ansheight=h; ans=root->val;
        }
        f(root->right, h+1);
    }
    int findBottomLeftValue(TreeNode* root) {
        f(root, 1);
        return ans;
    }
};
