class Solution {
public:
    int cnt[3];
    bool is(){
        return cnt[0]>0 && cnt[1]>0 && cnt[2]>0;
    }
    int numberOfSubstrings(string s) {
        int n=s.size();
        int ans=0;
        int l=0, r=0;
        for(; r<n;r++){
            cnt[s[r]-'a']++;
            while(is()){
                ans += n-r;
                cnt[s[l]-'a']--; 
                l++;
            }
        }
        return ans;
    }
};
