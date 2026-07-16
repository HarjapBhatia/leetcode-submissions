class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int m=matrix.size(), n=matrix[0].size();
        int ans=0;
        vector<vector<int>> dp(m, vector<int>(n,0));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j] == '1'){
                    dp[i][j] = (j==0 ? 1 : dp[i][j-1]+1);
                }
                else dp[i][j] = 0;
            }
        }

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                int cur=dp[i][j];
                for(int k=i;k<m && dp[k][j]; k++){
                    cur = min(cur, dp[k][j]);
                    ans = max(ans, cur * (k-i+1));
                }
            }
        }
        return ans;
    }
};
