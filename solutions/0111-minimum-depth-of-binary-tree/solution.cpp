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
    int minDepth(TreeNode* root) {
        if(!root) return 0;
        queue<TreeNode*> q;
        int lvl = 1;
        q.push(root);
        while(!q.empty()){
            int x = q.size();
            for(int i=0;i<x;i++){
                TreeNode* n = q.front();
                q.pop();
                if(!(n->left) && !(n->right)) return lvl;
                if(n->left) q.push(n->left);
                if(n->right) q.push(n->right);
            }
            lvl++;
        }
        return lvl;
    }
};
