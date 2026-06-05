class Solution {
public:
    // int fn(string st, int h, int l, vector<vector<int>> &dp){
    //     if(l>h) return 0;
    //     if(l==h) return 1;
    //     if(dp[h][l] != -1) return dp[h][l];
    //     if(st[l] == st[h]) 
    //         return dp[h][l] = 2 + fn(st, h-1, l+1, dp);
    //     return dp[h][l]=max(fn(st, h-1, l, dp), fn(st, h, l+1, dp));
    // }

    int longestPalindromeSubseq(string s) {
        // vector<vector<int>> dp(s.size(), vector<int>(s.size(),-1));
        // int ans = fn(s,s.size()-1, 0, dp);
        // return ans;
        int n=s.size();
        vector<vector<int>> dp(n, vector<int>(n,0));
        for(int i=n-1;i>=0;i--){
            for(int j=i;j<n;j++){
                if(i==j) {
                    dp[i][j]=1; continue;
                }
                if(s[i]==s[j]){
                    if(i==j-1) dp[i][j]=2;
                    else dp[i][j] = 2 + dp[i+1][j-1];
                }else{
                    dp[i][j] = max(dp[i+1][j], dp[i][j-1]);
                }
            }
        }
        return dp[0][n-1];
    }
};
