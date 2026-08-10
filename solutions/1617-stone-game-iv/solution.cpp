class Solution {
public:
    bool winnerSquareGame(int n) {
        vector<bool> dp(n+1, false);
        for(int i=0;i<=n;i++){
            if(dp[i]) continue;
            for(int j=1;j*j<=n; j++){
                if(i+j*j <= n) dp[i+j*j]=true;
            }
        }
        return dp[n];
    }
};
