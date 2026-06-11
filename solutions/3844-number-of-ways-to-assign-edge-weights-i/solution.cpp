class Solution {
public:
    int maxdep(vector<vector<int>> &adj){
        int n=adj.size();
        int dep=0;
        vector<bool> vis(n+1); vis[1]=true;
        queue<int> q; q.push(1);
        while(!q.empty()){
            int x = q.size();
            dep++;
            while(x--){
                int f = q.front(); q.pop();
                for(int i : adj[f]){
                    if(!vis[i]){
                        q.push(i); vis[i]=true;
                    }
                }
            }
        }
        return dep-1;
    }

    int assignEdgeWeights(vector<vector<int>>& edges) {
        vector<vector<int>> adj(1e5+1);
        for(auto a : edges){
            adj[a[0]].push_back(a[1]);
            adj[a[1]].push_back(a[0]);
        }
        int dep = maxdep(adj);
        // cout << dep << " ";
        int ans =1;
        dep--;
        while(dep--){
            ans = (ans*2)%1000000007;
        }
        return ans;
    }
};
