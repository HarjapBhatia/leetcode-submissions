class Solution {
using P = pair<int,int>;
public:
    // method-1: dfs!!
    // int mi = 1e5;
    // vector<vector<P>> adj;
    // vector<bool> vis;

    // void dfs(int src){
    //     if(vis[src]) return;
    //     vis[src] = true;
    //     for(auto neigh : adj[src]){
    //         mi = min(mi, neigh.second);
    //         dfs(neigh.first);
    //     }
    // }

    //method-2: DSU
    vector<int> par;
    int f(int x){
        if(x == par[x]) return x;
        return par[x] = f(par[x]);
    }
    int minScore(int n, vector<vector<int>>& roads) {
        par.resize(n+1);
        iota(par.begin(), par.end(), 0);

        for(auto &a : roads){
            par[f(a[0])] = f(a[1]);
        }
        int ans = 1e6;
        for(auto &a : roads){
            if(f(a[0]) == f(1))
                ans = min(ans, a[2]);
        }
        return ans;
        
        // adj.resize(n+1);
        // vis.resize(n+1, false);
        // for(auto &e:roads){
        //     adj[e[0]].push_back({e[1], e[2]});
        //     adj[e[1]].push_back({e[0], e[2]});
        // }
        // dfs(1);
        // return mi;
    }
};
