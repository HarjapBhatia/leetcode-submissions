class Solution {
public:
    string rle(string s){
        string res;
        int n=s.size();
        for(int i=0;i<n;i++){
            int cnt=1, j=i+1;
            while(j<n && s[i]==s[j]){
                cnt++; j++;
            }
            res += to_string(cnt);
            res += s[i];
            i=j-1;
        }
        return res;
    }
    string countAndSay(int n) {
        string ans="1";
        if(n==1) return ans;
        for(int i=2;i<=n;i++){
            ans = rle(ans);
        }
        return ans;
    }
};
