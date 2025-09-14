class Solution {
public:
    int earliestTime(vector<vector<int>>& tasks) {
        int n = tasks.size();
        int mn = 201;
        for(int i=0;i<n;i++){
            int sm = tasks[i][0] + tasks[i][1];
            mn = min(sm, mn);
        }
        return mn;
    }
};
