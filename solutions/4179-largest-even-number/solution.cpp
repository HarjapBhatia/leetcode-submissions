class Solution {
public:
    string largestEven(string s) {
        for(int i=s.size()-1; i>=0; i--){
            int dg = s[i]-'0';
            if(dg %2 == 0) return s.substr(0,i+1);
        }
        return "";
    }
};
