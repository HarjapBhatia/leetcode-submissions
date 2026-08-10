/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root || root==p || root==q) return root;
        //postorder traversal
        TreeNode* lf = lowestCommonAncestor(root->left, p,q);
        TreeNode* rg = lowestCommonAncestor(root->right, p,q);
        if(lf && rg) return root; // if both are there then return the ancestor
        return lf ? lf : rg; // if there's only 1 (either p or q)
    }
};
