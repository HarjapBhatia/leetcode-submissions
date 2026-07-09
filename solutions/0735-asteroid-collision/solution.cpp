class Solution {
public:
    vector<int> asteroidCollision(vector<int>& ast) {
        stack<int> st;
        for(int x : ast){
            bool f=false;
            while(!st.empty() && x<0 && st.top()>0){
                if(abs(st.top())==abs(x)){st.pop(); f=true; break;}
                else if(abs(x) > abs(st.top())) st.pop();
                else{f=true; break;}
            }
            if(!f) st.push(x);
        }
        vector<int> ans;
        while(!st.empty()) {ans.push_back(st.top()); st.pop();}
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
