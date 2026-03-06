class Solution {
public:
    bool isSubsequence(string s, string t) {
        int i=0;
        for(int k=0;k<t.size();k++){
            if(i<s.size() && s[i]==t[k]) i++;
        }
        return i==s.size();
    }
};
