class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> ump;
        stack<int> st;
        for(int x : nums2){
            while(!st.empty() && st.top() < x){
                ump[st.top()] = x;
                st.pop();
            }
            st.push(x);
        }
        vector<int> res;
        for(int x : nums1){
            res.push_back(ump.count(x) ? ump[x] : -1);
        }
        return res;
    }
};
