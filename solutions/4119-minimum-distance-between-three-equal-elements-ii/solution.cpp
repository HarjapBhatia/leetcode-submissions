class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        int n=nums.size();
        vector<int> bef(n,-1), af(n,-1);
        unordered_map<int,int> rec;
        for(int i=n-1;i>=0;i--){
            if(rec.count(nums[i])) af[i] = rec[nums[i]];
            rec[nums[i]] = i;
        }
        rec.clear();
        for(int i=0;i<n;i++){
            if(rec.count(nums[i])) bef[i] = rec[nums[i]];
            rec[nums[i]] = i;
        }
        int ans = 1e8;
        for(int i=0;i<n;i++){
            if(af[i]!=-1 && bef[i]!=-1) 
                ans = min(ans, af[i]-bef[i]);
        }
        return ans == 1e8 ? -1 : 2*ans;
    }
};
