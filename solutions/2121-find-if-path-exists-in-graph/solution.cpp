class Solution {
public:
    void dfs(vector<vector<int>>&adj, vector<int>&vis, int s, int d){
        vis[s] = 1;
        for(int i : adj[s]){
            if(!vis[i]) dfs(adj, vis, i, d);
        }
    }

    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        //dfs
        vector<vector<int>> adj(n);
        for(auto e : edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        vector<int> vis(n,0);
        dfs(adj, vis, source, destination);
        return vis[destination];

        // bfs
        // vector<vector<int>> adj(n);
        // for(auto e : edges){
        //     adj[e[0]].push_back(e[1]);
        //     adj[e[1]].push_back(e[0]);
        // }
        // if(n==1) return true;

        // vector<int> vis(n,0);
        // queue<int> q; q.push(source); vis[source]=1;

        // while(!q.empty()){
        //     int x = q.front(); q.pop();
        //     for(int i : adj[x]){
        //         if(i == destination) return true;
        //         if(!vis[i]){
        //             q.push(i); vis[i]=1;
        //         }   
        //     }
        // }

        // return false;

    }
};
