class Solution {
public:
    vector<vector<int>>res;
    vector<bool> vis;
    vector<int> temp;
    void f(vector<int> &v){
        if(temp.size()==v.size()){
            res.push_back(temp); return;
        }
        for(int i=0;i<v.size();i++){
            if(vis[i]) continue;
            if(i>0 && v[i] == v[i-1] && !vis[i-1]) continue;
            
            vis[i]=true; 
            temp.push_back(v[i]);
            f(v);
            temp.pop_back();
            vis[i]=false;
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n=nums.size();
        vis.resize(n,false);
        f(nums);
        return res;
    }
};
