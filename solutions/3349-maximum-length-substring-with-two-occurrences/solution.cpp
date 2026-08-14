class Solution {
public:
    int maximumLengthSubstring(string s) {
        unordered_map<char,int> fq;
        // for(char x : s) fq[x]++;
        int n=s.size(),l=0,ans=0;
        for(int r=0;l<n&&r<n;r++){
            fq[s[r]]++;
            while(fq[s[r]] > 2){
                fq[s[l]]--; l++;
            }
            ans = max(ans, r-l+1);
        }
        return ans;
    }
};
