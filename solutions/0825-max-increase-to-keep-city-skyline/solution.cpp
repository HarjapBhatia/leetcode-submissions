class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<int> ns(n,0), ew(n,0);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                ns[j] = max(ns[j], grid[i][j]);
                ew[i] = max(ew[i], grid[i][j]);
            }
        }
        int cnt =0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cnt += (min(ns[i], ew[j]) - grid[i][j]);
            }
        }

        return cnt;
    }
};
