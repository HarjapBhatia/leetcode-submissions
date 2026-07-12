// using T = tuple<int,int,int>;
using P = pair<int,int>;
class Solution {
public:
    vector<int> par,size;
    int find(int x){
        if(par[x] == x) return x;
        return par[x] = find(par[x]);
    }
    void merge(int u, int v){
        int pu=find(u), pv=find(v);
        if(pu==pv) return;
        if(size[pu]<size[pv]) swap(pu, pv);
        par[pv]=par[pu];
        size[pu] += size[pv];
    }
    int x[4] = {0,0,1,-1};
    int y[4] = {1,-1,0,0};

    vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries) {
        int m=grid.size(), n=grid[0].size();
        par.resize(n*m);
        iota(par.begin(), par.end(), 0);
        size.resize(n*m, 1);

        auto isval = [&](int i, int j) -> bool{
            return i>=0 && i<m && j>=0 && j<n;
        };

        vector<P> cells; // val,i*n+j
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                cells.push_back({grid[i][j], i*n+j});
            }
        }
        sort(cells.begin(), cells.end());

        vector<P> que; // val, idx
        for(int i=0;i<queries.size();i++){
            que.push_back({queries[i], i});
        }
        sort(que.begin(), que.end());

        vector<vector<bool>> vis(m, vector<bool>(n, false));
        vector<int> ans(que.size());

        int it=0;
        for(auto &[val, idx] : que){
            while(it < cells.size() && cells[it].first < val){
                
                int ref = cells[it].second;
                int r = ref/n, c = ref%n;
                vis[r][c] = true;

                for(int d=0;d<4;d++){
                    int dx = r+x[d], dy = c+y[d];
                    if(!isval(dx, dy)) continue;
                    if(vis[dx][dy]){
                        merge(ref, dx*n+dy);
                    }
                }
                it++;
            }

            if(!vis[0][0]){
                ans[idx] = 0;
            }else{
                ans[idx] = size[find(0)];
            }
        }

        return ans;
    }
};
