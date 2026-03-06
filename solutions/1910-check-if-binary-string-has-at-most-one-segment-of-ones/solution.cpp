class Solution {
public:
    bool checkOnesSegment(string s) {
        int n = s.size();
        int cnt = 0;
        bool is= false;
        for(int i=0;i<n;i++){
            if(s[i]=='1' && !is) cnt++, is = true;
            else if(s[i] == '0') is = false;
        }
        return cnt == 1;
    }
};
