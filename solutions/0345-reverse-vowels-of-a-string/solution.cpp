class Solution {
private:
    bool isvow(char x){
        if(x == 'A' || x == 'E' || x == 'I' || x == 'O' || x == 'U' || x == 'a' || x == 'e' || x == 'i' || x == 'o' || x == 'u'){
            return true;
        }
        return false;
    }
public:
    string reverseVowels(string s) {
        string vw = "";
        int n = s.size();
        for(int i=0;i<n;i++){
            if(isvow(s[i])) vw += s[i];
        }
        reverse(vw.begin(), vw.end());
        string res = "";
        int j = 0;
        for(int i=0;i<n;i++){
            if(isvow(s[i])) res += vw[j++];
            else res += s[i];
        }
        return res;
    }
};
