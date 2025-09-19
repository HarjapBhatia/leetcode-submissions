class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        int n = nums.size();
        int sm = 0;
        vector<int>vec(n);
        for(int i=0;i<n;i++){
            sm+=nums[i];
            vec[i] = sm;
        }
        return vec;
    }
};
