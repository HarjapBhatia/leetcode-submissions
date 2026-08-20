/*
idea: find out the prime factors of the numbers,
    if there is atleast one prime factor between two numbers (not 1), 
    that means the connection exist!!
*/
    
class Solution {
public:
    vector<int>par, size;
    int f(int u){
        if(u == par[u]) return u;
        return par[u] = f(par[u]);
    }

    void merge(int u, int v){
        int pu=f(u), pv=f(v);
        if(pv == pu) return; 
        par[pv] = pu;
        size[pu] += size[pv];
    }

    int largestComponentSize(vector<int>& nums) {
        int n=nums.size();
        int m = *max_element(nums.begin(),nums.end());
        par.resize(m+1);
        size.assign(m+1,0);
        for(int i:nums) {
            size[i]++;
            par[i] = i;
        }

        unordered_map<int,vector<int>> mp;

        for(int x : nums){
            int t=x;
            for(int i=2;i*i<=x;i++){
                if(t%i==0){
                    mp[i].push_back(x);
                    while(t%i==0) t/=i;
                }
            }
            if(t>1) mp[t].push_back(x);
        } 

        for(auto a : mp){
            for(int i=1;i<a.second.size();i++){
                merge(a.second[0],a.second[i]);
            }
        }
        // for(int i : size) cout << i << " ";
        return *max_element(size.begin(),size.end());
    }
};
