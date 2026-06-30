class Solution {
public:
    vector<int> dp;
    int f(vector<int>&v, int i){
        if(i==0 || i==1) return dp[i] = v[i];
        if(dp[i] != 1000) return dp[i];
        return dp[i] = v[i] + min(f(v,i-1), f(v,i-2));
    }

    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        dp.resize(n,1000);

        return min(f(cost, n-1), f(cost, n-2));
        // vector<int> dp(n, 1000);
        // for(int i=0;i<n;i++){
        //     if(i<2) dp[i]=cost[i];
        //     else{
        //         dp[i] = cost[i] + min(dp[i-1], dp[i-2]);
        //     }
        // }
        // return min(dp[n-1], dp[n-2]);
    }
};
