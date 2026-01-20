class Solution {
public:
    void fn(vector<int>&cd, vector<vector<int>>&res, vector<int>&vec, int t, int k, int i){
        if(t == k) {res.push_back(vec); return;}
        if(i >= cd.size() || t > k) return;
        vec.push_back(cd[i]);
        fn(cd, res, vec, t+cd[i], k, i); // for recusively adding the number and checking
        vec.pop_back(); // in case of k > t, it will pop from the vec
        fn(cd,res,vec,t,k,i+1);     // increase the index to add a new number and backtrack
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> vec;
        fn(candidates, res, vec, 0, target, 0);
        return res;
    }
};
