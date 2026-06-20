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
    vector<vector<int>> adj;
    void trav(TreeNode* root){
        if(!root) return;
        if(root->left){
            adj[root->val].push_back(root->left->val);
            adj[root->left->val].push_back(root->val);
        }
        if(root->right){
            adj[root->val].push_back(root->right->val);
            adj[root->right->val].push_back(root->val);
        }
        trav(root->left);
        trav(root->right);
    }
    int amountOfTime(TreeNode* root, int start) {
        adj = vector<vector<int>>(1e5+1);
        trav(root);
        int ans=0;
        vector<int> vis(1e5+1, 0);

        queue<int> q; q.push(start); vis[start]=1;
        while(!q.empty()){
            int x = q.size();
            while(x--){
                int f = q.front(); q.pop();
                for(int i : adj[f]){
                    if(!vis[i]){
                        vis[i]=1;
                        q.push(i);
                    }
                }
            }
            ans++;
        }
        return ans-1;
    }
};
