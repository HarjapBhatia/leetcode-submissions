class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        int n=nums.size();
        sort(nums.begin(), nums.end());
        long long ans=0;
        for(int i=0;i<n;i++){
            ans += upper_bound(nums.begin(), nums.end(), upper-nums[i])-nums.begin();
            ans -= lower_bound(nums.begin(), nums.end(), lower-nums[i])-nums.begin();
            if(lower <= 2*nums[i] && 2*nums[i] <= upper) ans--;
        }
        return ans/2;
    }
};
