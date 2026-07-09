class Solution {
public:
    bool isValid(string s) {
        unordered_map<char,char> mp = {
            {'}', '{'},{']', '['},{')', '('}
        };
        stack<char> st;
        for(char x : s){
            if(x == '(' || x == '{' || x == '[') {st.push(x); continue;}
            if(st.empty() || st.top() != mp[x]) return false;
            st.pop();
        }
        return st.empty();
    }
};
