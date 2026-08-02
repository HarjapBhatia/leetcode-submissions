/*
- create a suffix sum which will store the count of apples
- on every h_cut, check on top. on every v_cut check on left
- while cutting check if the top/left has 0 apple, cut is not possible
- 
- never cut on i=r-1 or j=c-1 cuz there's nothing to down/right of it
*/
class Solution {
public:
    const long long mod = 1000000007;
    int r=0,c=0;
    vector<vector<int>> suff;
    vector<vector<vector<int>>> dp;
    
    // row, col, cuts
    int f(int i, int j, int k){
        if(suff[i][j] == 0) return 0;
        if(k==0) return 1;
        if(dp[i][j][k] != -1) return dp[i][j][k];
        
        int ans=0;
        // hor
        for(int x=i;x<r-1;x++){
            if(suff[i][j] - suff[x+1][j] > 0){
               ans = (ans + f(x+1, j, k-1)) % mod;
            }
        }
        // ver
        for(int y=j;y<c-1;y++){
            if(suff[i][j] - suff[i][y+1] > 0){
               ans = (ans + f(i, y+1, k-1)) % mod;
            }
        }
        return dp[i][j][k] = ans;
    }

    int ways(vector<string>& pizza, int k) {
        r = pizza.size(); c=pizza[0].size();
        dp = vector<vector<vector<int>>>(r, vector<vector<int>>(c, vector<int>(k, -1)));
        suff = vector<vector<int>>(r, vector<int>(c,0));

        suff[r-1][c-1] = (pizza[r-1][c-1]=='A');
        for(int i=r-2;i>=0;i--){
            suff[i][c-1] = suff[i+1][c-1] + (pizza[i][c-1]=='A');
        }
        for(int j=c-2;j>=0;j--){
            suff[r-1][j] = suff[r-1][j+1] + (pizza[r-1][j]=='A');
        }
        for(int i=r-2;i>=0;i--){
            for(int j=c-2;j>=0;j--){
                suff[i][j] = suff[i][j+1] + suff[i+1][j] - suff[i+1][j+1] + (pizza[i][j] == 'A');
            }
        }

        // for(auto v : suff){
        //     for(int w : v){
        //         cout << w << " ";
        //     }
        //     cout << "\n";
        // }

        return f(0,0,k-1);
    }
};
