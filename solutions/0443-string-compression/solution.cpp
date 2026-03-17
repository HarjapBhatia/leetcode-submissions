class Solution {
public:
    int compress(vector<char>& chars) {
        string s;
        int j = 0, cnt = 1;
        for(int i=1;i<chars.size();i++){
            if(chars[j] == chars[i]) cnt++;
            else{
                s.push_back(chars[j]);
                if(cnt != 1) s += to_string(cnt);
                j = i;
                cnt = 1;
            }
        }
        s.push_back(chars[j]);
        if(cnt != 1) s += to_string(cnt);
        for(int i=0;i<s.size();i++) chars[i] = s[i];
        return s.size();
    }
};
