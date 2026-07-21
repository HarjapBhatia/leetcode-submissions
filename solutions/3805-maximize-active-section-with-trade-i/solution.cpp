class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        int n=s.size();
        int c1 = count(s.begin(),s.end(),'1');
        
        int i=0, cnt=0, prv=INT_MIN;
        while(i<n){
            int x=i;
            while(i<n && s[i]==s[x]) i++;
            if(s[x]=='0'){
                int tmp = i-x;
                cnt = max(cnt, prv+tmp);
                prv=tmp;
            }
        }

        return c1+cnt;
    }
};
