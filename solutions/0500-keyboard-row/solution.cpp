class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        string s1="qwertyuiop";
        string s2="asdfghjkl";
        string s3="zxcvbnm";
        vector<string> res;
        for(string s : words){
            //s1
            bool is1=true;
            for(char x : s){
                if(s1.find(tolower(x)) == string::npos) {is1 = false; break;}
            }
            if(is1){
                res.push_back(s);
                continue;
            }

            //s2
            bool is2=true;
            for(char x : s){
                if(s2.find(tolower(x)) == string::npos) {is2 = false; break;}
            }
            if(is2){
                res.push_back(s);
                continue;
            }

            //s3
            bool is3=true;
            for(char x : s){
                if(s3.find(tolower(x)) == string::npos) {is3 = false; break;}
            }
            if(is3){
                res.push_back(s);
                continue;
            }
        }
        return res;
    }
};
