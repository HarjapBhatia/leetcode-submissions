class Solution {
public:
    bool check(string res){
        if(res.size() == 1) return true;
        int i=0,j=res.size()-1;
        while(i<=j){
            if(res[i]!=res[j]) return false;
            i++,j--;
        }
        return true;
    }
    bool isPalindrome(string s) {
        string res = "";
        for(char ch : s){
            if(ch >= 'A' && ch <= 'Z') res += tolower(ch);
            else if(ch >= 'a' && ch <= 'z') res += ch;
            else if(ch >= '0' && ch <= '9') res += ch;
        }
        
        return check(res);
    }
};
