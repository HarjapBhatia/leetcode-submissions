class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n=arr.size();
        unordered_map<int, vector<int>> hash;
        for(int i=0;i<n;i++){
           hash[arr[i]].push_back(i); 
        }
        queue<int> q;
        unordered_set<int> vis;
        q.push(0); vis.insert(0);
        int lvl=0;
        
        while(!q.empty()){
            int qsz = q.size();

            for(int k=0;k<qsz;k++){
                // method - 1:
                int i = q.front(); q.pop();

                if(i==n-1) return lvl;
                vector<int> v = hash[arr[i]];
                v.push_back(i+1); v.push_back(i-1);

                for(int x : v){
                    if(x >= 0 && x < n && vis.find(x) == vis.end()){
                        vis.insert(x); q.push(x);
                    }
                }
                hash[arr[i]].clear();
                
                // method - 2 :
                // int i1 = i+1, i2 = i-1;
                
                // if(i1 >=0 && i1 < n && vis.find(i1) == vis.end()){
                //     if(i1 == n-1) return lvl+1;
                //     q.push(i1); vis.insert(i1);
                // }
                // if(i2 >= 0 && i2 < n && vis.find(i2) == vis.end()){
                //     if(i2 == n-1) return lvl+1;
                //     q.push(i2); vis.insert(i2);
                // }
                // for(int x : hash[arr[i]]){
                //     if(vis.find(x) != vis.end()) continue;
                //     if(x == n-1) return lvl+1;
                //     q.push(x); vis.insert(x);
                // }
                // hash[arr[i]].clear();
            }

            lvl++;
        }
        return -1;
        // return lvl-1;
    }
};
