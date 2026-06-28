typedef long long ll;
using T = tuple<ll,int,int>;
class Solution {
public:
    vector<long long> minTimeMaxPower(int n, vector<vector<int>>& edges, int power, vector<int>& cost, int source, int target) {
        vector<vector<pair<int,int>>> adj(n);
        for(auto &e:edges){
            adj[e[0]].push_back({e[1], e[2]});
        }

        vector<vector<ll>> dist(n, vector<ll>(power+1, LLONG_MAX));
        priority_queue<T, vector<T>,greater<T>> pq;
        dist[source][power]=0;
        pq.push({0,source,power});

        while(!pq.empty()){
            auto [t,u,rem] = pq.top(); pq.pop();

            if(t!=dist[u][rem]) continue;
            if(rem < cost[u]) continue;
            int np = rem-cost[u];
            for(auto &[v,w] : adj[u]){
                if(dist[v][np] > t+w){
                    dist[v][np]=t+w;
                    pq.push({t+w, v,np});
                }
            }
        }
        ll bt = LLONG_MAX; int bp = -1;
        for(int p=0;p<=power;p++){
            if(dist[target][p] < bt){
                bt = dist[target][p]; bp=p;
            }else if(dist[target][p] == bt) bp = max(bp,p);  
        }
        if(bt == LLONG_MAX) return {-1,-1};
        return {bt,bp};
    }
};
