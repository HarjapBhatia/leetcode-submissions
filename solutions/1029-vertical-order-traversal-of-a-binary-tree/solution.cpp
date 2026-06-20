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
    map<int,vector<pair<int,int>>> mp;
    void trav(TreeNode* root, int col, int row){
        if(!root) return;
        mp[col].push_back({row, root->val});
        trav(root->left, col-1, row+1);
        trav(root->right, col+1, row+1);
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        trav(root,0,0);
        vector<vector<int>> ans;
        for(auto it : mp){
            auto v = it.second;
            
            sort(v.begin(), v.end(), 
            [&](const pair<int,int>&a, const pair<int,int>&b){
                // sorting by val when same rows
                if(a.first == b.first){ 
                    return a.second < b.second;
                }
                // sorting by rows
                return a.first < b.first;
            });
            vector<int> temp;
            for(auto a : v){
                temp.push_back(a.second);
            }
            ans.push_back(temp);
        }

        return ans;
    }
};
