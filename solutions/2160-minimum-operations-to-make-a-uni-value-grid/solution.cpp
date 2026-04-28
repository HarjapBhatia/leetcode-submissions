class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        int rm = grid[0][0]%x;
        int n=grid.size(), m = grid[0].size();
        vector<int> vec;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(rm != grid[i][j]%x) return -1;
                vec.push_back(grid[i][j]);
            }
        }
        sort(vec.begin(), vec.end());
        int b = vec[vec.size()/2];
        int op = 0;
        for(int a : vec){
            op += {abs(a-b)/x};
        }
        return op;
    }
};
