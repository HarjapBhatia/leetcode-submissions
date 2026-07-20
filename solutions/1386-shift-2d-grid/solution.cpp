class Solution {
public:
    // void debug(vector<int> &tem){
    //     cout << "debug: ";
    //     for(int ii : tem) cout << ii << " ";
    //     cout << "\n";
    // }

    void rshift(vector<int>&v){
        reverse(v.begin(),v.end());
        reverse(v.begin()+1, v.end());
    }
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int m=grid.size(), n=grid[0].size();

        vector<int> v;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                v.push_back(grid[i][j]);
            }
        }
        
        while(k--) rshift(v);
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                grid[i][j] = v[i*n+j];
            }
        }

        return grid;
        // while(k--){
        //     vector<int> tem(m);
        //     for(int i=0;i<m;i++){
        //         tem[i] = grid[i][n-1];
        //     }
            
        //     // debug(tem);
        //     rshift(tem);

        //     for(int i=0;i<m;i++){
        //         for(int j=n-1;j>0;j--){
        //             grid[i][j] = grid[i][j-1];
        //         }
        //     }
        //     for(int i=0;i<m;i++){
        //         grid[i][0] = tem[i];
        //     }
        // }
        // return grid;
    }
};
