#include <stack>
#include <map>
class Solution {
public:
    bool isValid(string s) {
        stack <char> st;
        map <char,char> m = {
            {')', '('},
            {'}', '{'},
            {']', '['}
        };
        for (char p : s){
            if ((p=='(') || (p=='{') || (p=='[')){
                st.push(p);
            }else{
                if(st.empty() || st.top()!=m[p]){
                    return false;
                }
                st.pop();
            }
        }
        return st.empty();
    }
};
