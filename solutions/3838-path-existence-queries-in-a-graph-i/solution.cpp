using P = pair<int,int>;
class Solution {
public:
    vector<int> par;
    int find(int x) {
        if(par[x]==x) return x;
        return par[x]=find(par[x]);
    }
    void merge(int u,int v){ par[find(u)] = find(v); }

    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        par.resize(n);
        iota(par.begin(), par.end(),0);


        priority_queue<P>pq;
        for(int i=0;i<n;i++){
            pq.push({nums[i], i});
        }

        P x = pq.top(); 

        while(!pq.empty()){
            P cur = pq.top(); pq.pop();
            if(abs(cur.first - x.first) <= maxDiff){
                merge(cur.second, x.second);
            }
            x=cur;
        }

        vector<bool> ans;
        for(auto &q : queries){
            ans.push_back(find(q[0]) == find(q[1]));
        }

        return ans;
    }
};
