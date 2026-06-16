class Solution {
public:

    // bool f(vector<vector<int>>&dp, vector<int>&v, int i,int sm, int &tot){
    //     if(i == v.size() || 2*sm > tot) 
    //         return false;
    //     if(dp[i][sm] != -1) 
    //         return dp[i][sm];
    //     if(2*sm == tot) 
    //         return dp[i][sm]=1;
        
    //     return dp[i][sm] = f(dp,v, i+1, sm + v[i], tot) || f(dp,v, i+1, sm, tot);
    // }

    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int tot = accumulate(nums.begin(), nums.end(),0);
        if(tot&1) return false;
        tot /= 2;
        
        vector<vector<bool>> dp(n+1, vector<bool>(tot+1,false));
        dp[0][0]=true;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=tot;j++){
                // if the num is greater than sum we want, ignore it
                if(nums[i-1] > j) dp[i][j] = dp[i-1][j];
                // else leave it || take it
                else{
                    dp[i][j] = dp[i-1][j] || dp[i-1][j-nums[i-1]];
                }
            }
        }

        return dp[n][tot];
        // return f(dp, nums, 0, 0,tot);
    }
};
