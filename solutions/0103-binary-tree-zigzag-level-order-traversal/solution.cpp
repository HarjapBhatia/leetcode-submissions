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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(!root) return {};
        vector<vector<int>> res;
        int lvl=0; bool f=true;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int x = q.size();
            res.push_back({});
            for(int i=0;i<x;i++){
                TreeNode* n = q.front();
                q.pop();
                res[lvl].push_back(n->val);
                // if(f){
                //     if(n->right) q.push(n->right);
                //     if(n->left) q.push(n->left);
                //     f=false;
                // }else{
                //     if(n->left) q.push(n->left);
                //     if(n->right) q.push(n->right);
                //     f=true;
                // }
                if(n->left) q.push(n->left);
                if(n->right) q.push(n->right);
            }
            lvl++;
        }
        for(int i=0;i<res.size();i++){
            if(i&1){
                reverse(res[i].begin(), res[i].end());
            }
        }
        return res;
    }
};
