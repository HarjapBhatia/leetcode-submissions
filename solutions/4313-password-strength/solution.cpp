class Solution {
public:
    int passwordStrength(string password) {
        unordered_set<char> vis;
        int res=0;
        for(char x : password){
            if(vis.find(x) != vis.end()) continue;
            if('a' <= x && x <= 'z') res += 1;
            else if('A' <= x && x <= 'Z') res += 2;
            else if('0' <= x && x <= '9') res += 3;
            else if(x == '!' || x=='@' || x=='#' || x=='$') res += 5;
            vis.insert(x);
        }
        return res;
    }
};
