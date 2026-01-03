class Solution {
public:
    string reversePrefix(string s, int k) {
        string n = "";
        for(int i=k-1;i>=0;i--) n+=s[i];
        for(int i=k;i<s.size();i++) n+=s[i];
        return n;
    }
};
