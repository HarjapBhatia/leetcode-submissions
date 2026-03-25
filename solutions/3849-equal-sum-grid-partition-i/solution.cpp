typedef long long ll;
class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<ll> xsum(n), ysum(m);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                xsum[i] += grid[i][j];
                ysum[j] += grid[i][j];
            }
        }
        for(int i=1;i<n;i++) xsum[i] += xsum[i-1];
        for(int j=1;j<m;j++) ysum[j] += ysum[j-1];
        ll tx = xsum[n-1], ty = ysum[m-1];
        for(int i=0;i<n;i++){
            if(xsum[i] == tx-xsum[i]) return true;
        }
        for(int i=0;i<m;i++){
            if(ysum[i] == ty-ysum[i]) return true;
        }
        return false;
    }
};
