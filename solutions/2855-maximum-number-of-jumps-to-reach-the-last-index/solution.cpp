class Solution {
public:
    int maximumJumps(vector<int>& nums, int target) {
        int n=nums.size();
        vector<int> dp(n, INT_MIN);
        dp[0] = 0;
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                int dif=nums[j]-nums[i];
                if(-1*target <= dif && dif <= target){
                    dp[i] = max(dp[i], 1+dp[j]);
                }
            }    
        }
        return dp[n-1]<0 ? -1 : dp[n-1];
    }
};
