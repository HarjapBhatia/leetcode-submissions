class Solution {
public:
    string toLowerCase(string s) {
        string st = "";
        for(char ch : s){
            if((int)ch >= 65 && (int)ch <= 90) ch += 32;
            st += ch;
        }
        return st;
    }
};
