class Solution {
public:
    void dfs(vector<vector<int>>&adj, vector<int> &vis, int src){
        if(vis[src]) return;
        vis[src] = 1;
        for(int i : adj[src])
            if(!vis[i]){dfs(adj,vis,i);}
    }

    int findCircleNum(vector<vector<int>>& is) {
        int n=is.size();
        vector<vector<int>> adj(n+1);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i!=j && is[i][j]){
                    adj[i+1].push_back(j+1);
                    // adj[j+1].push_back(i+1);
                }
            }
        }
        int cnt=0;
        vector<int> vis(n+1,0);
        for(int i=1;i<=n;i++){
            if(vis[i]) continue;
            dfs(adj, vis, i);
            cnt++;
        }
        return cnt;
    }
};
