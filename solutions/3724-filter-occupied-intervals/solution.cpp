class Solution {
public:
    vector<vector<int>> filterOccupiedIntervals(vector<vector<int>>& occ, int fs, int fe) {
        vector<vector<int>> res;
        sort(occ.begin(), occ.end());
        auto prev = occ[0]; int n=occ.size();
        for(int i=1;i<n;i++){
            auto cur = occ[i];
            if(cur[0] <= prev[1]){
                prev = {prev[0], max(prev[1], cur[1])};
            }else if(prev[1]+1 == cur[0]){
                prev = {prev[0], cur[1]};
            }else{
                res.push_back(prev); prev=cur;
            }
        }
        res.push_back(prev);
        vector<vector<int>> ans;
        for(auto a : res){
            int l = a[0], r=a[1];
            if(r < fs || l>fe) ans.push_back({l,r});
            else{
                if(l<fs) ans.push_back({l, fs-1});
                if(r>fe) ans.push_back({fe+1, r});
            }
        }
        return ans;
    }
};
