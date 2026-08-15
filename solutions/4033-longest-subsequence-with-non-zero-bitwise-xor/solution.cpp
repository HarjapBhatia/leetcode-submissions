class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int n=nums.size(),l=0,xr=0,r=0,cntz=0;
        while(r<n){
            if(nums[r]==0) cntz++;
            xr ^= nums[r++];
        }
        if(xr) return n;
        if(cntz==n) return 0;

        return n-1;   
    }
};
