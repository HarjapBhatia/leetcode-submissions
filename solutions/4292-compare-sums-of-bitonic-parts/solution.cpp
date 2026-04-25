class Solution {
public:
    int compareBitonicSums(vector<int>& nums) {
        long long tot=nums[0], inc=nums[0];
        int pk=0;
        for(int i=1;i<nums.size();i++){
            if(nums[i] > nums[i-1]) {pk = i; inc += nums[i];}
            tot += nums[i];
        }
        tot += nums[pk];
        if(inc < tot-inc) return 1;
        if(inc > tot-inc) return 0;
        return -1;
    }
};
