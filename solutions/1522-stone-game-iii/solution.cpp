class Solution {
public:
    string stoneGameIII(vector<int>& v) {
        int n=v.size();
        vector<int>dp(n+1,0);
        for(int i=n-1;i>=0;i--){
            dp[i]=-5e8; int cur=0;
            for(int j=i;j<min(i+3,n);j++){
                cur += v[j];
                dp[i] = max(dp[i], cur-dp[j+1]);
            }
        }
        if(dp[0]>0) return "Alice";
        else if(dp[0]<0) return "Bob";
        return "Tie";
    }
};
