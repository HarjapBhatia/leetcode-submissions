class Solution {
public:
    int n;
    vector<vector<int>>res;
    void f(vector<int>&can, int i, int cur, vector<int> &temp, int target){
        if(cur == target){
            res.push_back(temp); return;
        }
        if(i >= n || cur > target) return;
        for(int j=i;j<n;j++){
            if(j > i && can[j] == can[j-1]) continue;
            if(cur + can[j] > target) break;
            temp.push_back(can[j]);
            f(can, j+1, cur+can[j], temp, target);
            temp.pop_back();
        }

    }
    vector<vector<int>> combinationSum2(vector<int>& can, int target) {
        n = can.size();
        vector<int> t;
        sort(can.begin(), can.end());
        f(can,0,0,t,target);
        return res;
    }
};
