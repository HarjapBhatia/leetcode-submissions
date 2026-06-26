class Solution {
public:

    int f(vector<int> &v, int i, vector<int>&dp){
        if(i>=v.size()) return 0;
        if(dp[i]!=-1) return dp[i];
        return dp[i] = max(v[i]+f(v,i+2, dp), f(v,i+1, dp));
    }


    int rob(vector<int>& nums) {
        // method : 1 
        // int n=nums.size();
        // vector<int> dp(n,0);
        // dp[0] = nums[0];
        // if(n >= 2) dp[1] = max(nums[1], nums[0]);
        // for(int i=2;i<n;i++){
        //     dp[i] = max(dp[i-2]+nums[i], dp[i-1]);
        // }
        // return dp[n-1];

        //method : 2 (optimal)
        // int p1=0, p2=0;
        // for(int x: nums){
        //     int cur = max(p1, p2+x);
        //     p2 = p1;
        //     p1 = cur;
        // }
        // return p1;

        //method 0: rec + dp
        vector<int> dp(nums.size()+1,-1);
        if(nums.size() <= 2) 
            return *max_element(nums.begin(), nums.end());
        return f(nums, 0, dp);
    }
};
