typedef long long ll;
class Solution {
public:
    const ll inf = 1e18;
    int r,c;
    vector<vector<vector<ll>>> dp;
    vector<vector<int>> wc;
    bool isval(int i, int j){return i>=0 && i<r && j>=0 && j<c;}

    ll f(int i, int j, int t){
        if(!isval(i,j)) return inf;
        if(i==r-1 && j==c-1) return 0;
        if(dp[i][j][t] != -1) return dp[i][j][t];
        ll ans=inf;
        if(t&1){
            ans = min(ans, (i+2)*(j+1)+f(i+1,j,0));
            ans = min(ans, (i+1)*(j+2)+f(i,j+1,0));
        }else{  
            ans = min(ans, wc[i][j] + f(i,j,1));
        }
        return dp[i][j][t]=ans;
    }

    long long minCost(int m, int n, vector<vector<int>>& waitCost) {
        r=m; c=n; wc=waitCost;
        dp = vector<vector<vector<ll>>>(m,vector<vector<ll>>(n,vector<ll>(2,-1)));
        return 1+f(0,0,1);
    }
};
