class Solution {
public:
    bool isMiddleElementUnique(vector<int>& nums) {
        int n = nums.size();
        int mi = nums[n/2];
        return count(nums.begin(), nums.end(), mi) == 1;
    }
};
