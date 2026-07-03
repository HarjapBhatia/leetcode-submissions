class Solution {
using P = pair<int, int>;
using LP = pair<long long, int>;
public:
    vector<vector<P>> adj;
    
    bool dijk(int mid, int n, long long k){
        vector<long long> dist(n,LLONG_MAX);
        priority_queue<LP, vector<LP>, greater<LP>> pq;
        dist[0]=0; pq.push({0,0});

        while(!pq.empty()){
            auto [d, u] = pq.top(); pq.pop();
            if(d > k) return false;
            if(u==n-1) return true;
            if(d > dist[u]) continue;

            for(auto &[v,w] : adj[u]){
                if(w < mid) continue;
                if(dist[v] > dist[u]+w){
                    dist[v] = dist[u]+w;
                    pq.push({dist[v], v});
                }
            }
        }
        return false;
    }

    int findMaxPathScore(vector<vector<int>>& edges, vector<bool>& online, long long k) {
        int n=online.size();
        adj.resize(n);
        int l=INT_MAX, r=0;

        for(auto &e : edges){
            if(!online[e[0]] || !online[e[1]]) continue;
            adj[e[0]].push_back({e[1], e[2]});
            l=min(l,e[2]);
            r=max(r,e[2]);
        }

        if(!dijk(l,n,k)) return -1;
        while(l<=r){
            int mi = (l+r)>>1;
            if(dijk(mi, n, k)){
                l=mi+1;
            }else{
                r=mi-1;
            }
        }
        return r;

    }
};
