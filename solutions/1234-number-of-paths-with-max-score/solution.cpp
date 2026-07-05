#define mod 1000000007
#define P pair<int,int>
class Solution {
public:
    vector<vector<P>>dp;
    vector<string> v;
    
    P f(int i, int j){
        if(i<0 || j<0) return {-1,0};
        if(v[i][j] == 'X') return {-1,0};
        if(v[i][j] == 'E') return {0,1};

        if(dp[i][j].first != INT_MIN) return dp[i][j];

        int val = (v[i][j] == 'S') ? 0 : v[i][j]-'0';
        P up = f(i-1,j);
        P lef = f(i,j-1);
        P dg = f(i-1,j-1);

        int mx = max({up.first, lef.first, dg.first});
        if(mx == -1) return dp[i][j] = {-1,0};
        int ways=0;
        if(up.first == mx) ways = (ways+up.second)%mod;
        if(lef.first == mx) ways = (ways+lef.second)%mod;
        if(dg.first == mx) ways = (ways+dg.second)%mod;
        
        return dp[i][j] = {mx+val, ways};
    }

    vector<int> pathsWithMaxScore(vector<string>& board) {
        int n=board.size();    
        v=board;
        dp.assign(n, vector<P>(n, {INT_MIN,0}));
        auto ans = f(n-1,n-1);
        if(ans.first == -1) return {0,0};
        return {ans.first, ans.second};
    }
};
