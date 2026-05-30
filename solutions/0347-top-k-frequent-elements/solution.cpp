class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> fq;
        for(int i : nums) fq[i]++;

        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>q;
        for(auto &it : fq){
            q.push({it.second, it.first});
            if(q.size() > k) q.pop();
        }
        vector<int> ans;
        while(!q.empty()){
            ans.push_back(q.top().second);
            q.pop();
        }
        return ans;
        // int n=nums.size();
        // map<int, int> mp;
        // for(int i:nums) mp[i]++;
        // vector<pair<int,int>> vp; 
        // for(auto it : mp) vp.push_back({it.first, it.second});
        // sort(vp.begin(), vp.end(), [&](auto &a, auto &b){
        //     return a.second > b.second;
        // });
        // vector<int> res;
        // for(int i=0;i<k;i++){
        //     res.push_back(vp[i].first);
        // }
        // return res;
    }
};
