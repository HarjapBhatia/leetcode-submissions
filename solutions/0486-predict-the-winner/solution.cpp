class Solution {
public:
    int n;
    vector<int> v;
    // turn = 1/0 (p1/p2)
    // bool f(int i, int j, int s1, int s2, int turn){
        // if(i==j){
        //     turn ? s1 += v[i] : s2 += v[i];
        //     return s1 >= s2;
        // }
        // if(i>j) return s1 >= s2;
        
        // bool ans=false;
        // if(turn)
        //     ans = f(i+1, j, s1+v[i], s2, turn^1) ||
        //         f(i, j-1, s1+v[j], s2, turn^1);
        // else 
        //     ans = f(i+1, j, s1, s2+v[i], turn^1) && 
        //         f(i, j-1, s1, s2+v[j], turn^1);
        // return ans;
    // }

    vector<vector<int>> dp;
    int f_with_dp(int i, int j){
        if(i==j) return v[i];
        if(dp[i][j] != -1) return dp[i][j];

        int l = v[i] - f_with_dp(i+1, j);
        int r = v[j] - f_with_dp(i, j-1);
        return dp[i][j] = max(l,r);
    }

    bool predictTheWinner(vector<int>& nums) {
        n=nums.size();
        v=nums;
        dp.assign(n, vector<int>(n, -1));
        // return f(0, n-1, 0, 0, 1);
        return f_with_dp(0,n-1) >= 0;
    }
};
