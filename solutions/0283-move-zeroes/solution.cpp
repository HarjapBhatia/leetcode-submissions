class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        int i = 0;
        for(int x : nums){
            if(x != 0) nums[i++] = x;
        }
        while(i<n) nums[i++]=0;
    }
};
