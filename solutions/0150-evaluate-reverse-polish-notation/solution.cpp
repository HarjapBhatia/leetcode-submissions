class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for(string s : tokens){
            if(s == "+"){
                int s = st.top(); st.pop();
                int f = st.top(); st.pop();
                st.push(f+s);
            }else if(s=="-"){
                int s = st.top(); st.pop();
                int f = st.top(); st.pop();
                st.push(f-s);
            }else if(s=="*"){
                int s = st.top(); st.pop();
                int f = st.top(); st.pop();
                st.push(f*s);
            }else if(s=="/"){
                int s = st.top(); st.pop();
                int f = st.top(); st.pop();
                st.push(f/s);
            }else st.push(stoi(s));
        }
        return st.top();
    }
};
