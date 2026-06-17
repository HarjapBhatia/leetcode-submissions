class Solution {
public:
    char processStr(string s, long long k) {
        long long cnt=0;
        for(char x : s){
            if(x=='*'){
                if(cnt) cnt--;
            }else if(x=='#') cnt *=2;
            else if(x=='%') continue;
            else cnt++;
        }
        if(k > cnt-1) return '.';
        for(int i=s.size()-1;i>=0;i--){
            if(s[i] == '*'){
                cnt++;
            }else if(s[i] == '#'){
                if(k+1 > cnt/2) k -= cnt/2;
                cnt /= 2;
            }else if(s[i] == '%'){
                k = cnt-k-1;
            }else{
                if(k == cnt-1) return s[i];
                else cnt--;
            }
        }

        return '.';
    }
};
