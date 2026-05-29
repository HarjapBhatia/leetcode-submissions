class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.size();
        // if(n==0) return 0;
        vector<int> cnt(256,-1);
        int mx=0, i=0;
        for(int j=0;j<n;j++){
            if(cnt[s[j]] >= i) {
                i = cnt[s[j]] + 1;
            }
            cnt[s[j]]=j;
            mx = max(mx, j-i+1);
        }
        return mx;
    }
};
