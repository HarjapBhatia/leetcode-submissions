class Solution {
public:
    vector<vector<int>> res;
    void f(int i, int target, vector<int> &temp, int k){
        if(i > 9){
            if(!target && temp.size()==k) res.push_back(temp);
            return;
        }
        if(!target && temp.size() == k){
            res.push_back(temp); return;
        }
        temp.push_back(i);
        f(i+1,target-i,temp,k);
        temp.pop_back();
        f(i+1,target,temp,k);
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int>temp;
        f(1,n,temp,k);
        return res;
    }
};
