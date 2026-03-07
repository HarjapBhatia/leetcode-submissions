class Solution {
public:
    int minFlips(string s) {
        int n = s.size();
        s+=s;
        int f1=0, f2 =0;
        int ans = n;
        for(int i=0;i<s.size();i++){
            if(s[i] != (i % 2 ? '1' : '0')) f1++;
            if(s[i] != (i % 2 ? '0' : '1')) f2++;

            if(i >= n) {
                if(s[i-n] != ((i-n) % 2 ? '1' : '0')) f1--;
                if(s[i-n] != ((i-n) % 2 ? '0' : '1')) f2--;
            }
            if(i>=n-1) ans = min(ans, min(f1,f2));
        }
        return ans;
    }
};
