typedef long long ll;
class Solution {
public:
    vector<ll> dp;
    int fn(vector<int>&coins, int a){
        int mi = 1e9;
        if(a == 0) return 0;
        if(dp[a] != -1) return dp[a];
        for(int x : coins){
            if(a-x >= 0) mi = min(mi, 1+fn(coins, a-x));
        }
        return dp[a] = mi;
    }
    int coinChange(vector<int>& coins, int amount) {
        dp.resize(amount+1,-1);
        ll ans = fn(coins, amount);
        return ans == 1e9 ? -1 : ans;
    }
};
