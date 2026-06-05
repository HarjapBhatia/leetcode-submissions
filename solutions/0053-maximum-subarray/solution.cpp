class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n+1, -1e5);
        for(int i=0;i<n;i++){
            dp[i+1] = max(dp[i]+nums[i], nums[i]);
        }
        return *max_element(dp.begin(), dp.end());
        // int curr=nums[0], mx = nums[0];
        // for(int i=1;i<nums.size();i++){
        //     curr = max(nums[i], curr+nums[i]);
        //     mx = max(mx, curr);
        // }
        // return mx;
    }
};
