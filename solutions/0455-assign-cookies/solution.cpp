class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int n=g.size(), m=s.size();
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int cnt=0;
        auto ix=s.begin();
        for(int i=0;i<min(n,m);i++){
            ix = lower_bound(ix, s.end(), g[i]);
            if(ix == s.end()) break;
            cnt++; ix++;
        }
        return cnt;
    }
};
