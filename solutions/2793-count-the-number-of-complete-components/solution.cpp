class Solution {
public:
    vector<int> par,size;
    int find(int x){
        if(par[x] == x) return x;
        return par[x] = find(par[x]);
    }
    void merge(int u, int v){
        int pu = find(u), pv=find(v);
        if(pu==pv) return;
        if(pu > pv){
            par[pv]=pu;
            size[pu] += size[pv]; 
        }else{
            par[pu]=pv;
            size[pv] += size[pu]; 
        }
    }
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        par.resize(n);
        iota(par.begin(), par.end(), 0);
        size.resize(n,1);

        unordered_map<int,int> ecnt;
        for(auto &e : edges){
            merge(e[0], e[1]);
        }
        for(auto &e : edges){
            int x = find(e[0]);
            ecnt[x]++; //no of edges
        }
        int cnt=0;
        for(int i=0;i<n;i++){
            if(find(i) == i){
                int a = size[i];
                if(2*ecnt[i] == a*(a-1)) cnt++;
            }
        }
        return cnt;
    }
};
