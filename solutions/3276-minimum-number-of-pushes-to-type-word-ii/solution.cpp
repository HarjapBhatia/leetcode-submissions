class Solution {
public:
    int minimumPushes(string w) {
        vector<int> fq(26,0);
        for(char x : w) fq[x-'a']++;
        sort(fq.rbegin(), fq.rend());
        int ans=0;
        for(int i=0;i<26;i++){
            if(!fq[i]) break;
            ans += fq[i] * (i/8 + 1);
        }
        return ans;
    }
};
