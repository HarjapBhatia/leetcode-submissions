class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> ps(n);
        ps[0]=nums[0];
        unordered_map<int,int> mp;
        for(int i=1;i<n;i++) ps[i] = nums[i]+ps[i-1];
        int cnt =0;
        for(int i=0;i<n;i++){
            int x = ps[i];  
            if(x==k) cnt++;

            if(mp.find(x-k) != mp.end())
                cnt += mp[x-k]; 
            mp[x]++;
        }
        return cnt;
    }
};
