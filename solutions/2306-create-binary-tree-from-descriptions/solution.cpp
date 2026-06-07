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
    TreeNode* createBinaryTree(vector<vector<int>>& des) {
        unordered_set<int> ischild;
        unordered_map<int, TreeNode*> tn;
        for(auto x : des){
            if(!tn[x[0]]) 
                tn[x[0]] = new TreeNode(x[0]);
            
            if(!tn[x[1]])
                tn[x[1]] = new TreeNode(x[1]); 
            
            ischild.insert(x[1]);
        
            if(x[2])
                tn[x[0]]->left = tn[x[1]];
            else 
                tn[x[0]]->right = tn[x[1]];

        }

        int rt = 0;
        for(auto x : des){
            if(ischild.find(x[0]) == ischild.end()){
                rt=x[0]; break;
            }
        }

        return tn[rt];

    }
};
