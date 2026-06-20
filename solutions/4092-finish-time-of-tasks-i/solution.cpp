class Solution {
public:
    vector<vector<int>> adj;
    vector<int> base;

    bool isleaf(int x){
        return adj[x].empty();
    }

    long long dfs(int src){
        if(isleaf(src)) return 1ll*base[src];

        long long ear=LLONG_MAX;
        long long lat=0;
        
        for(int i : adj[src]){
            long long cur = dfs(i);
            ear=min(ear, cur);
            lat=max(lat, cur);
        }
        return 2ll*lat - ear + base[src];
    }
    
    long long finishTime(int n, vector<vector<int>>& edges, vector<int>& baseTime) {
        adj = vector<vector<int>>(n);
        for(auto e : edges){
            adj[e[0]].push_back(e[1]);
        }
        base = baseTime;
        return dfs(0);
            
    }
};
