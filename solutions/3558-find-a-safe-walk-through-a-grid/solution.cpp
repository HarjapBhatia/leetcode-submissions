class Solution {
public:
    bool isval(int i, int j, vector<vector<int>>&grid){
        return i>=0 && i<grid.size() && j>=0 && j<grid[0].size();
    }
    vector<vector<int>> dir = {{1,0}, {-1,0}, {0,-1}, {0,1}};
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int n=grid.size(), m=grid[0].size();
        vector<vector<int>> best(n,vector<int>(m,-1));
        priority_queue<vector<int>> q;
        q.push({health-grid[0][0], 0,0}); 
        best[0][0] = health-grid[0][0];
        while(!q.empty()){
            auto cur = q.top(); q.pop();
            int h=cur[0], f=cur[1], s=cur[2];
            if(h < best[f][s]) continue;
            if(f == n-1 && s==m-1 && h > 0) return true;
            for(auto d : dir){
                int dx = f+d[0], dy = s+d[1];
                if(isval(dx,dy, grid)) {
                    int nh = h-grid[dx][dy];
                    if(nh>0 && best[dx][dy] < nh){
                        best[dx][dy]=nh;
                        q.push({nh,dx,dy});
                    }
                }
            }
        }
        return false;
    }
};
