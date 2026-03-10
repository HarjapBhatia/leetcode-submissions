class Solution {
public:
    vector<int> dp;
    int fn(int i){
        if(i<=1) return 1;
        if(dp[i] != -1) return dp[i];
        return dp[i] = fn(i-1) + fn(i-2);
    }
    int climbStairs(int n) {
        // if(n==1) return 1;
        // int a=1,b=1;
        // for(int i=1;i<n;i++){
        //     int temp = b; 
        //     b = a+b;
        //     a = temp;
        // }
        // return b;
        dp.resize(n+1,-1);
        return fn(n);
    }
};
