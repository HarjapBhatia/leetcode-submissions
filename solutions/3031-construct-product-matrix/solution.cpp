// idea : doing product of all suffixes and all prefixes, excluding the element itself
typedef long long ll;
class Solution {
public:
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        int n=grid.size(), m=grid[0].size();
        vector<vector<int>> res(n, vector<int>(m,1));

        // suffix, but excluding the element itself
        ll suf = 1;
        for(int i=n-1;i>=0;i--){
            for(int j=m-1;j>=0;j--){
                res[i][j] = suf;
                suf = (suf*grid[i][j])%12345;
            }
        }

        // prefix, but excluding the element itself
        ll pref = 1;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                res[i][j] = (res[i][j]*pref)%12345;
                pref = (pref*grid[i][j])%12345;
            }
        }

        return res;

    }
};
