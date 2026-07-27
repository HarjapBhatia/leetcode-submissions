class Solution {
public:
    // i+j-1, i+j, i+j+1
    vector<vector<int>> dp;
    vector<int> v;
    unordered_map<int,int> exist; //for checking valid stone position
    bool f(int i, int k, int n){
        if(i==n-1) return true;
        if(dp[i][k] != -1) return dp[i][k];

        for(int jmp=k-1;jmp<=k+1;jmp++){
            if(jmp<=0) continue;
            int nxt = v[i]+jmp; // next position
           
            if(exist.count(nxt)){
                if(f(exist[nxt], jmp, n))   
                    return dp[i][k] = true;
            } 
        }

        return dp[i][k]=false;
    }

    bool canCross(vector<int>& stones) {
        int n=stones.size();
        v=stones;
        if(n>1 && stones[1]!=1) return false;
        dp = vector<vector<int>> (n, vector<int>(n+1, -1));
        for(int i=0;i<n;i++) exist[stones[i]]=i;
        return f(1,1,n);
    }
};
