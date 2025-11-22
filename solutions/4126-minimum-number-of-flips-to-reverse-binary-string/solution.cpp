class Solution {
public:
    string toBinary(int n) {
        if (n == 0) return "0";
        string s = "";
        while (n > 0) {
            s.push_back('0' + (n % 2));
            n /= 2;
        }
        reverse(s.begin(), s.end());
        return s;
    }

    int minimumFlips(int n) {
        string s = toBinary(n);
        string sr = s;
        reverse(sr.begin(), sr.end());
        int cnt = 0;
        for(int i=0;i<s.size();i++){
            if((s[i] - '0') ^ (sr[i] - '0')) cnt++;
        }
        return cnt;
    }
};
