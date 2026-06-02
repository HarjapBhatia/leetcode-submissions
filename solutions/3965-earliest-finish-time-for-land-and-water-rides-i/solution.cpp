class Solution {
public:
    int f(vector<int>&a1, vector<int>&a2, vector<int>&b1, vector<int>&b2){
        int ans =INT_MAX;
        for(int i=0;i<a1.size();i++){
            ans = min(ans, a1[i]+a2[i]);
        }
        int ans2=INT_MAX;
        for(int j=0;j<b1.size();j++){
            ans2 = min(ans2, max(ans, b1[j])+b2[j]);
        }
        return ans2;
    }

    int earliestFinishTime(vector<int>& lst, vector<int>& ld, vector<int>& wst, vector<int>& wd) {
        // vector<vector<int>> l, w;
        // int n = landStartTime.size();
        // int m = waterStartTime.size();
        // for(int i=0;i<n;i++){
        //     l.push_back({landStartTime[i], landDuration[i]});
        // }
        // for(int i=0;i<m;i++){
        //     w.push_back({waterStartTime[i], waterDuration[i]});
        // }

        int x = f(lst, ld, wst, wd);
        int y = f(wst, wd, lst, ld);
        return min(x,y);
    }
};
