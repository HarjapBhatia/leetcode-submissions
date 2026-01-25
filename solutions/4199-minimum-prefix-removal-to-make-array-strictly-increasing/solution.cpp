class Solution {
public:
    int minimumPrefixLength(vector<int>& nums) {
        int ix = 0, n = nums.size();
        if(nums.size() == 1) return 0;
        for(int i=1; i<n; i++){
            if(nums[i] <= nums[i-1]) ix = i;
        } 
        return ix;
    }
};
