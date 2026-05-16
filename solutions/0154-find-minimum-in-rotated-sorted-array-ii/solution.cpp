class Solution {
public:
    int f(int l, int r, vector<int>&nums){
        if(l == r || nums[l] < nums[r]) return nums[l];
        int m = (l+r)/2;
        return min(f(l,m,nums), f(m+1,r,nums));
    }

    int findMin(vector<int>& nums) {
        return f(0, nums.size()-1, nums);
    }
};
