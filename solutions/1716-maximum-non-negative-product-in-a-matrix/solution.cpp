typedef long long ll;
class Solution {
public:
    int maxProductPath(vector<vector<int>>& grid) {
        int n = grid.size(), m=grid[0].size();

    // if next no. is +ve, we'll need max +ve no. inorder to maximise
        vector<vector<ll>> mx(n, vector<ll>(m,0));
    // if next no. is -ve, we'll need min -ve no. inorder to maximise
        vector<vector<ll>> mi(n, vector<ll>(m,0));

        mi[0][0] = mx[0][0] = grid[0][0];
        
        for(int j=1;j<m;j++) 
            mi[0][j] = mx[0][j] = mx[0][j-1]*grid[0][j];
        for(int i=1;i<n;i++) 
            mx[i][0] = mi[i][0] = mx[i-1][0]*grid[i][0];
        
        // from 1,1
        for(int i=1;i<n;i++){
            for(int j=1;j<m;j++){
                ll x = grid[i][j];
                
                ll a = x * mx[i-1][j];
                ll b = x * mx[i][j-1];
                ll c = x * mi[i-1][j];
                ll d = x * mi[i][j-1];
            
                mx[i][j] = max({a,b,c,d});
                mi[i][j] = min({a,b,c,d});
            }
        }
        ll ans = mx[n-1][m-1];
        if(ans < 0) return -1;
        return ans%1000000007;
    }
};
