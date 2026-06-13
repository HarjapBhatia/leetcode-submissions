class Solution {
public:
    vector<string> ans;
    unordered_map<char, string> hsh = {
        {'2', "abc"},
        {'3', "def"},
        {'4', "ghi"},
        {'5', "jkl"},
        {'6', "mno"},
        {'7', "pqrs"},
        {'8', "tuv"},
        {'9', "wxyz"}
    };

    void f(string &s, string x, int i){
        if(i==s.size()){
            ans.push_back(x); return;
        }
        string let = hsh[s[i]];
        for(char ch : let){
            f(s, x+ch, i+1);
        }
    }

    vector<string> letterCombinations(string digits) {
        f(digits,"",0);
        return ans;
    }
};
