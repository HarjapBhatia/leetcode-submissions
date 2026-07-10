class Solution {
public:
    string removeOuterParentheses(string s) {
        unordered_set<int>us;
        stack<char> st; int i=0;
        for(int i=0;i<s.size();i++){
            if(st.empty()) us.insert(i);
            char ch = s[i];
            if(ch == '(') st.push(ch);
            else {
                st.pop(); 
                if(st.empty()) us.insert(i);
            }
        }
        string res;
        for(int i=0;i<s.size();i++){
            if(us.find(i)!=us.end()) continue;
            res += s[i];
        }
        return res;
    }
};
