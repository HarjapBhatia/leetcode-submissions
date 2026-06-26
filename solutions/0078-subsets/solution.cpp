class Solution {
public:
    vector<vector<int>> res;
    void f(vector<int> &v, int i, vector<int> &temp){
        if(i == v.size()) {
            res.push_back(temp); return;
        }
        temp.push_back(v[i]);
        f(v, i+1, temp);
        temp.pop_back();
        f(v, i+1, temp);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int>temp; 
        f(nums, 0, temp);
        return res;
    }
};
