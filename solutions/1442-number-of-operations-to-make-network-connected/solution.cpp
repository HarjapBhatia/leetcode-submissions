class Solution {
public:
    // void bfs(vector<vector<int>>&adj, vector<int> &vis, int &cnt, int s){
    //     queue<int> q; q.push(s); vis[s]=1;
    //     while(!q.empty()){
    //         int x = q.front(); q.pop();
    //         for(int i : adj[x]){
    //             if(vis[i] == -1){
    //                 q.push(i); vis[i]=1;
    //             }else cnt++;
    //         }
    //     }   
    // }

    void dfs(vector<vector<int>>&adj, vector<int>&vis, int src){
        if(vis[src]) return;
        vis[src]=1;
        for(int i : adj[src]){
            dfs(adj,vis,i);
        }
    }

    int makeConnected(int n, vector<vector<int>>& connections) {
        if(connections.size() < n-1) return -1;
        vector<vector<int>> adj(n);
        for(auto e: connections){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }    
        vector<int> vis(n,0);
        int cnt=0;
        for(int i=0;i<n;i++){
            if(vis[i]) continue;
            dfs(adj,vis,i);
            cnt++;
        }

        return cnt-1;


        // int mulvis = 0;
        // bfs(adj, vis, mulvis, 0);
        // // mulvis/=(n-1);
        // mulvis/=2;
        // int notviscnt=0;
        // for(int i : vis){
        //     if(i==-1) notviscnt++;
        // }
        // cout << mulvis << " " << notviscnt;
        // return mulvis >= notviscnt ? mulvis-notviscnt : -1 ;
    }
};
