class Solution {
public:
    string removeDuplicates(string s) {
        // stack<char> st;
        // for(char c : s){
        //     if(!st.empty() && st.top() == c) {
        //         st.pop(); continue;
        //     }
        //     st.push(c);
        // }
        // string res;
        // while(!st.empty()){
        //     res += st.top(); st.pop();
        // }
        // reverse(res.begin(), res.end());
        // return res;
        int i=0;
        for(int j=0;j<s.size();j++){
            s[i] = s[j];
            if(i>0 && s[i] == s[i-1]) i-=2;
            i++;
        }
        return s.substr(0,i);
    }
};
