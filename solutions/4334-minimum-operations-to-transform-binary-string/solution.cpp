class Solution {
public:
    int minOperations(string s1, string s2) {
        int n=s1.size();
        int cnt=0;
        for(int i=0;i<n-1;i++){
            if(s1[i]==s2[i]) continue;
            if(s1[i] == '0'){
                s1[i] = '1'; cnt++;
            }else{
                if(s1[i+1] == '1'){
                    s1[i]='0'; s1[i+1]='0'; cnt++;
                }else{
                    s1[i]='0'; s1[i+1]='0'; cnt+=2;
                }
            }
        }

        if(s1[n-1] != s2[n-1]){
            if(s1[n-1]=='0') cnt++;
            else{
                if(n==1) return -1;
                cnt+=2;
            }
        }
        
        return cnt;
    }
};
