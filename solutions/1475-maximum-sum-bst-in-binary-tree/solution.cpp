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
class Node{
public:
    int sum, max_node, min_node;
    Node(int sum, int max_node, int min_node){
        this->sum = sum; 
        this->max_node=max_node; 
        this->min_node = min_node;
    }
};

class Solution {
public:
    int ans=0;
        
    Node* f(TreeNode* root){
        if(!root) return new Node(0,INT_MIN,INT_MAX);
        Node* l = f(root->left);
        Node* r = f(root->right);

        if(l->max_node < root->val and root->val < r->min_node){
            int cur = root->val + l->sum + r->sum;
            ans = max(ans, cur);

            return new Node(
                cur, 
                max(root->val, r->max_node), //max_node
                min(root->val, l->min_node) //min_node
            );
        }
        delete l; delete r;
        return new Node(0,INT_MAX,INT_MIN);
    }

    int maxSumBST(TreeNode* root) {
        f(root); return ans;    
    }
};
