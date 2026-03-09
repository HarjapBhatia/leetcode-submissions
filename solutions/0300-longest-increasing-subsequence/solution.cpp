class Solution {
public:
    // O(n^2) solution
    // vector<int> dp;
    // int fn(vector<int>&v, int i){
    //     if(dp[i] != -1) return dp[i];
    //     int ans = 1;
    //     for(int j=0;j<i;j++){
    //         if(v[i] > v[j]) ans = max(ans, 1+fn(v,j));
    //     }
    //     return dp[i] = ans;
    // }

    int lengthOfLIS(vector<int>& nums) {
        // dp.resize(nums.size(),-1);
        // int ans = 0;
        // for(int i=0;i<nums.size();i++){
        //     ans = max(ans, fn(nums, i));
        // }
        // return ans;

        // method-2: no need of dp, binary search(lower bound) + greedy
        // ans in O(nlogn)
        vector<int> v;
        for(int x: nums){
            auto it = lower_bound(v.begin(), v.end(), x);
            if(it == v.end()) v.push_back(x);
            else *it = x; 
        }
        return v.size();
    }
};
