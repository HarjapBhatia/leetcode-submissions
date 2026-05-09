class Solution {
public:
    vector<vector<int>> rotateGrid(vector<vector<int>>& grid, int k) {
        int t=0,b=grid.size()-1,l=0,r=grid[0].size()-1;
        while(t<b && l<r){
            int ln=b-t, wd=r-l;
            int per=2*ln+2*wd;
            int rem=k%per;
            while(rem--){
                int tmp=grid[t][l];
                for(int i=l;i<r;i++)
                    grid[t][i] = grid[t][i+1];
                for(int i=t;i<b;i++)
                    grid[i][r] = grid[i+1][r];
                for(int i=r;i>l;i--)
                    grid[b][i] = grid[b][i-1];
                for(int i=b;i>t;i--)
                    grid[i][l] = grid[i-1][l];
                
                grid[t+1][l] = tmp;
            }
            t++;l++;b--;r--;
        }
        return grid;
    }
};
