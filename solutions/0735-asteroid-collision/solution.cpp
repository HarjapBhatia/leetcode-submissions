class Solution {
public:
    vector<int> asteroidCollision(vector<int>& a) {
        stack<int> st;
        int n = a.size();
        for (int x : a) {
            bool f = false;
            while(!st.empty() && x < 0 && st.top() > 0){
                if(abs(x) == abs(st.top())){
                    st.pop(); f=true; break;
                }else if(abs(st.top()) < abs(x)) st.pop();
                else {f=true; break;}
            }
            if(!f) st.push(x);
        }
        vector<int> res;
        while(!st.empty()){
            res.push_back(st.top());
            st.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
