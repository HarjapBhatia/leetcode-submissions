class Solution {
public:
    string reverseWords(string s) {
        vector<string> v;
        int n = s.size();
        for(int i=0;i<n;i++){
            string st="";
            int j=i;
            if(s[i] == ' ') continue;
            while(j<n && s[j] != ' ') st = st + s[j++];
            i = j;
            if(st!="")v.push_back(st);
        }
        reverse(v.begin(), v.end());
        string res = "";
        for(int i=0;i<v.size();i++) {
            res += v[i];
            if(i!=v.size()-1) res += ' ';
        }
        return res;
    }
};
