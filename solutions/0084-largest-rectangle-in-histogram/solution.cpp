class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int>pmi(n,-1), nmi(n,n);
        stack<int> st;
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && heights[st.top()] >= heights[i]) st.pop();
            if(!st.empty()) nmi[i] = st.top();
            st.push(i);
        }
        while(!st.empty()) st.pop();
        for(int i=0;i<n;i++){
            while(!st.empty() && heights[st.top()] >= heights[i]) st.pop();
            if(!st.empty()) pmi[i] = st.top();
            st.push(i);
        }
        int mx = 0;
        for(int i=0;i<n;i++){
            int ar = (nmi[i] - pmi[i] - 1) * heights[i];
            mx = max(mx, ar);
        }
        return mx;
    }
};
