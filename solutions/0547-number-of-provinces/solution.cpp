class Solution {
public:
    vector<int> par;
    int find(int x){
        if(x == par[x]) return x;
        return par[x] = find(par[x]);
    }

    void join(int u, int v){
        int p_u = find(u), p_v = find(v);
        if(p_u == p_v) return;
        par[p_u] = p_v;
    }

    int findCircleNum(vector<vector<int>>& is) {
        int m=is.size(), n=is[0].size();
        par.resize(n+1);
        iota(par.begin(), par.end(),0);

        for(int i=0;i<m;i++){
            for(int j=i+1;j<n;j++){
                if(is[i][j]){
                    join(i+1, j+1);
                }
            }
        }
        
        int cnt = 0;
        for(int i=1;i<=m;i++){
            if(par[i] == i) cnt++;
        }

        return cnt;
    }
};
