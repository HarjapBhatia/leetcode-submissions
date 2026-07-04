class Solution {
public:
    int maxValidPairSum(vector<int>& nums, int k) {
        int n=nums.size();
        int ans=0, mx=nums[0];
        for(int i=k;i<n;i++){
            mx = max(mx, nums[i-k]);
            ans=max(ans, mx+nums[i]);
        }
        return ans;
    }
};
