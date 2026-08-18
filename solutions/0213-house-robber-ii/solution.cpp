class Solution {
public:
    int n;
    vector<int> dp;
    int f(vector<int>&nums, int l, int r){
        if(l>r) return 0;
        if(dp[l] != -1) return dp[l];
        int rb = nums[l] + f(nums, l+2, r);
        int nrb = f(nums, l+1, r);
        return dp[l] = max(rb,nrb);
    }

    int solve(vector<int>&v, int l, int r){
        dp.assign(v.size(),-1);
        return f(v,l,r);
    }

    int rob(vector<int>& nums) {
        n=nums.size();
        if(nums.size() <= 2) 
            return *max_element(nums.begin(),nums.end());
        
        int ans1 = solve(nums,0,n-2);
        int ans2 = solve(nums,1,n-1);
        return max(ans1,ans2);
    }
};
