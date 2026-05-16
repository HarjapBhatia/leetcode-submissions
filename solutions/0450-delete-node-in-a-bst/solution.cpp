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
    TreeNode* succ(TreeNode* cur){
        cur = cur->right;
        while(cur && cur->left) 
            cur = cur->left;
        return cur;
    }

    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root) return root;
        if(root->val > key) 
            root->left = deleteNode(root->left, key);
        else if(root->val < key) 
            root->right = deleteNode(root->right, key);
        else {
            if(!root->left){
                TreeNode* t = root->right;
                delete root;
                return t;
            }
            if(!root->right){
                TreeNode* t = root->left;
                delete root;
                return t;
            }
            
            TreeNode* s = succ(root);
            root->val = s->val;
            root->right = deleteNode(root->right, s->val);
        }
        return root;
    }
};
