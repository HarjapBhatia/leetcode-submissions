class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& env) {
        int n=env.size();
        sort(env.begin(), env.end(), [&](vector<int>&a, vector<int>&b){
            if(a[0]==b[0]) return a[1] > b[1];
            return a[0] < b[0];
        });

        vector<int> v;
        for(auto a:env){
            auto it = lower_bound(v.begin(),v.end(), a[1]);
            if(it == v.end()) v.push_back(a[1]);
            else *it = a[1];
        }
        return v.size();
    }
};
