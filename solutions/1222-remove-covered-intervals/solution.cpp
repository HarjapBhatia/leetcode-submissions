class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& it) {
        int n=it.size();
        sort(it.begin(), it.end(), [&](vector<int> &a, vector<int> &b){
            if(a[0] == b[0]) return a[1]>b[1];
            return a[0] < b[0];
        });
        // for(auto x : it){
        //     cout << x[0] << " " << x[1] << "\n";
        // }
        // vector<vector<int>> res;
        int cnt=1;
        auto p = it[0];
        for(int i=1;i<n;i++){
            auto cur = it[i];
            if(p[1] < cur[1]){
                // res.push_back(p);
                cnt++; p=cur;
            }
        }
        // res.push_back(p);
        // return res.size();
        return cnt;
    }
};
