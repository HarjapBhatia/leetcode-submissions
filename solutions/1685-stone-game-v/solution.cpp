class Solution {
public:
    vector<vector<int>> dp;
    
    int f(vector<int>&v, int l, int r){
        if(l==r) return 0;
        if(dp[l][r]) return dp[l][r];

        int sum = accumulate(v.begin()+l, v.begin()+r+1, 0);
        int ans = 0;
        int lsum=0;
        for(int i=l;i<r;i++){
            lsum += v[i];
            int rsum = sum-lsum;

            if(lsum > rsum){
                ans = max(ans, rsum + f(v,i+1,r));
            }else if(lsum < rsum){
                ans = max(ans, lsum + f(v,l,i));
            }else{
                ans = max(
                    ans, 
                    max(lsum + f(v,l,i), rsum + f(v,i+1,r))
                );
            }
        }
        return dp[l][r] = ans;
    }

    int stoneGameV(vector<int>& sv) {
        int n=sv.size();
        dp.assign(n,vector<int>(n));
        return f(sv,0,n-1);
    }
};
