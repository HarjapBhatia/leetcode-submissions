class Solution {
public:
    long long weightedSum(vector<int>& p, vector<int>& nums) {
        int n=p.size();
        vector<vector<int>> adj(n);
        for(int i=1;i<n;i++){
            adj[p[i]].push_back(i);
        }

        vector<int> ht(n);
        queue<int> q;
        ht[0]=1; q.push(0); int h=1;
        while(!q.empty()){
            int u=q.front(); q.pop();
            h = max(h,ht[u]);
            for(int v:adj[u]){
                ht[v]=1+ht[u]; q.push(v);
            }
        }

        long long ans=0;
        for(int i=0;i<n;i++){
            ans += (1ll * nums[i]* (h-ht[i]+1));
        }
        return ans;
    }
};
