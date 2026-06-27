class Solution {
public:
    vector<vector<int>> res;
    void f(vector<int>&v, int i){
        if(i>=v.size()){
            res.push_back(v); return;
        }
        for(int j=i;j<v.size();j++){
            swap(v[i], v[j]);
            f(v,i+1);
            swap(v[i], v[j]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        f(nums, 0);
        return res;
    }
};
