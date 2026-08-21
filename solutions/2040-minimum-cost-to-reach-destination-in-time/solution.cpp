class Solution {
public:
    int minCost(int mxt, vector<vector<int>>& edges, vector<int>& fees) {
        int n=fees.size();
        vector<vector<pair<int,int>>> adj(n);
        for(auto e:edges){
            adj[e[0]].push_back({e[1],e[2]});
            adj[e[1]].push_back({e[0],e[2]});
        }
        vector<vector<int>> dist(n, vector<int>(mxt+1, 1e9));
    //cost, city, time
        // priority_queue<tuple<int,int,int>> pq;
        priority_queue<
            tuple<int,int,int>,
            vector<tuple<int,int,int>>,
            greater<tuple<int,int,int>>
        > pq;

        dist[0][0] = fees[0];
        pq.push({fees[0], 0, 0});

        while(!pq.empty()){
            auto [cost, u, time] = pq.top(); pq.pop();

            if(u == n-1) return cost;

            if(cost > dist[u][time]) continue;


            for(auto [v, t] : adj[u]){
                
                int nt = t+time, nc = cost + fees[v];

                if(nt > mxt) continue;
                if(nc < dist[v][nt]){
                    dist[v][nt] = nc;
                    pq.push({nc, v, nt});
                }
            }

        }

        return -1;

    }
};
