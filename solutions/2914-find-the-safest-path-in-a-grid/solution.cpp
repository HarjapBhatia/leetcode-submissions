class Solution {
public:
    vector<vector<int>> dir = {{0,1},{0,-1},{-1,0},{1,0}};
    bool isvalid(vector<vector<int>> &grid, int i, int j){
        return (i>=0 && i<grid.size()) && (j>=0 && j<grid[0].size());
    }
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int n=grid.size(), m=grid[0].size();
        queue<pair<int,int>> q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] == 1){
                    q.push({i,j});
                    grid[i][j]=0;
                }else{
                    grid[i][j]=-1;
                }
            }
        }

        while(!q.empty()){
            auto [f,s] = q.front(); q.pop();
            for(auto &d:dir){
                int di = f+d[0], dj = s+d[1];
                if(isvalid(grid,di,dj) && grid[di][dj]==-1){
                    grid[di][dj] = grid[f][s]+1;
                    q.push({di, dj});
                }
            }
        }


        priority_queue<vector<int>> pq;
        pq.push({grid[0][0], 0,0});
        grid[0][0]=-1;

        while(!pq.empty()){
            auto t = pq.top(); pq.pop();
            if(t[1] == n-1 && t[2] == m-1) return t[0];
            
            for(auto &d : dir){
                int di = t[1]+d[0], dj = t[2]+d[1];
                if(isvalid(grid,di,dj) && grid[di][dj]!=-1){
                    pq.push({min(t[0], grid[di][dj]), di, dj});
                    grid[di][dj]=-1;
                }
            }
        }
        return -1;
    }
};
