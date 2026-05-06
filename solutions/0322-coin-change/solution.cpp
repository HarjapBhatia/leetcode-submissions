class Solution {
public:
    int coinChange(vector<int>& c, int amt) {
        int n = c.size();
        vector<int> dp(amt+1,1e8);
        dp[0]=0;
        for(int i=1;i<=amt;i++){
            for(int x:c){
                if(i>=x) dp[i] = min(dp[i], 1+dp[i-x]);
            }
        }
        return dp[amt] == 1e8 ? -1 : dp[amt];
    }
};
