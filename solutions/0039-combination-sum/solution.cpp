class Solution {
public:
    void f(vector<int> &v, vector<int>&t, vector<vector<int>> &ans, int sm, int i, int k){
        if(sm == k) {ans.push_back(t); return;}
        if(i>=v.size() || sm > k) return;
        t.push_back(v[i]);
        f(v, t, ans, sm+v[i], i, k);
        t.pop_back();
        f(v, t, ans, sm, i+1, k);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> t;
        f(candidates, t, ans, 0, 0, target);
        return ans;
    }
};
