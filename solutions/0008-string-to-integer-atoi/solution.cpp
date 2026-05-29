class Solution {
public:
    int myAtoi(string s) {
        int n = s.size();
        if(n==0) return 0;
        bool isneg = false, islead = true;
        // if(s[0]=='-') isneg=true;
        string m;
        for(int i=0;i<n;i++){
            char x = s[i];
            if('0'<= x && x <= '9') {m += x; islead=false;}
            else if((x == '-' || x=='+')&& islead) {
                if(x=='+') isneg = false;
                else isneg = true;
                islead = false;
            }
            else if(x==' ' && islead) continue;
            else break;
        }
        if(m.size()==0) return 0;
        long long ans = 0;
        for (char c : m) {
            ans = ans*10 + (c-'0');
            if (!isneg && ans>INT_MAX) return INT_MAX;
            if (isneg && -ans < INT_MIN) return INT_MIN;
        }
        if(isneg) ans *=-1;
        return (int)ans;
    }
};
