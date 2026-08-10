class Solution {
public:
    vector<vector<int>>dp;

    int f(int s, int e, vector<int>&cuts){
        if(e-s<=1) return 0;
        if(dp[e][s] != -1) return dp[e][s];
        int ans = INT_MAX;
        for(int i=s+1;i<e;i++){
            int x = (cuts[e]-cuts[s]) + f(s,i,cuts) + f(i,e,cuts);
            ans = min(ans, x);
        }
        return dp[e][s] = ans;
    }

    int minCost(int n, vector<int>& cuts) {
        cuts.push_back(0);
        cuts.push_back(n);
        sort(cuts.begin(), cuts.end()); //0...cut1...cut2...cut3...n
        dp = vector<vector<int>>(cuts.size(), vector<int>(cuts.size(),-1));
        return f(0,cuts.size()-1,cuts);
    }
};
