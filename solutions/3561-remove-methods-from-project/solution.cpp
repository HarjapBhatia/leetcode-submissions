class Solution {
public:
    void dfs(vector<int>&vis, vector<vector<int>>&adj, int k){
        vis[k] = 1;
        for(int &x: adj[k]){
            if(!vis[x]) dfs(vis,adj,x);
        }
    }
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& inv) {
        vector<vector<int>> adj(n);
        for(auto a:inv){
            adj[a[0]].push_back(a[1]);
        }

        vector<int> vis(n,0);
        dfs(vis,adj,k);
        vector<int>ans;
        for(auto &a : inv){
            if(!vis[a[0]] and vis[a[1]]){
                for(int i=0;i<n;i++) ans.push_back(i);
                return ans;
            }
        }

        for(int i=0;i<n;i++){
            if(!vis[i]) ans.push_back(i);
        }
        
        return ans;
    }
};
