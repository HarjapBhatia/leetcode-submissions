class Solution {
public:
    bool backspaceCompare(string s, string t) {
        string a, b;
        for(char x : s){
            if(x == '#'){
                if(!a.empty()) a.pop_back();
                continue;
            } 
            a.push_back(x);
        }
        for(char x : t){
            if(x == '#'){
                if(!b.empty()) b.pop_back();
                continue;
            } 
            b.push_back(x);
        }
        return a==b;
    }
};
