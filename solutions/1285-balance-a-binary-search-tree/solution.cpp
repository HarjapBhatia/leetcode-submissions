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
    void trav(TreeNode* root, vector<int> &vec){
        if(!root) return;
        trav(root->left, vec);
        vec.push_back(root->val);
        trav(root->right, vec);
    }
    TreeNode* fn(vector<int> &vec, int l, int r){
        if(l>r) return nullptr;
        int m=(l+r)/2;
        TreeNode* temp = new TreeNode(vec[m]);
        temp->left = fn(vec, l, m-1);
        temp->right = fn(vec, m+1, r);
        return temp;
    }
    TreeNode* balanceBST(TreeNode* root) {
        vector<int> vec;
        trav(root, vec);
        return fn(vec, 0, vec.size()-1);
    }
};
