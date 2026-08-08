/*
idea-
keep a window of n-k size and move it and check it
*/
class Solution {
public:
    int maxScore(vector<int>& cp, int k) {
        int n=cp.size(), win_size = n-k;
        int sm = accumulate(cp.begin(),cp.end(),0);
        int cur=0,i=0,j=0;
        for(i=0;i<win_size;i++){
            cur += cp[i];
        }
        int ans=sm-cur;
        for(i=win_size;i<n;i++){
            cur += cp[i];
            cur -= cp[j++];
            ans = max(ans, sm-cur);
        }
        return ans;
    }
};
