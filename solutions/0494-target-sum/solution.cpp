class Solution {
public:
    int dp[21][2001];
    // 2001 for offset vals, range [-1k, +1k]
    int f(vector<int> &v, int tg, int i, int cur){
        if(i==v.size()) return cur == tg;
        if(dp[i][cur+1000] != -1) return dp[i][cur+1000];

        return dp[i][cur+1000] = f(v,tg,i+1,cur+v[i])
        +f(v,tg,i+1,cur-v[i]); 
        +f(v,tg,i+1,cur); 
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        memset(dp, -1, sizeof(dp));
        return f(nums, target, 0, 0);
    }
};
