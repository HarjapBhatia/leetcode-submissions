class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n=nums.size(),p=0,ans=0;
        unordered_map<int,int> mp;
        for(int i=0;i<n;i++){
            p+=nums[i];
            if(p==k) ans++; 
            if(mp.find(p-k) != mp.end()) ans += mp[p-k];
            mp[p]++;
        }
        return ans;
    }
};
