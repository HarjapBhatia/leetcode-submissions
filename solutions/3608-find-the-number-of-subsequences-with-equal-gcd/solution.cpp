#define mod 1000000007
class Solution {
public:
    // i,g1,g2
    // int dp[201][201][201];
    vector<vector<vector<int>>> dp;

    int f(vector<int> &nums, int i, int g1, int g2){
        if(i>=nums.size()){
            return g1==g2;
        }

        if(dp[i][g1][g2] != -1) return dp[i][g1][g2];

        long long ans=0;
        ans += f(nums,i+1,g1,g2);
        ans %= mod;
        ans += f(nums,i+1,gcd(g1,nums[i]),g2);
        ans %= mod;
        ans += f(nums,i+1,g1,gcd(g2,nums[i]));
        ans %= mod;

        return dp[i][g1][g2] = (int)ans;
    }

    int subsequencePairCount(vector<int>& nums) {
        // memset(dp, -1, sizeof(dp));
        int n=nums.size();
        int mx=*max_element(nums.begin(), nums.end());
        dp = vector<vector<vector<int>>>(n+1,vector<vector<int>>(mx+1, vector<int>(mx+1,-1)));
        return f(nums,0,0,0)-1;    
    }
};
