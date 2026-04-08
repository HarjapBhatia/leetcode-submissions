#define mod 1000000007
class Solution {
public:
    void fn(vector<int>&nums, vector<int>q){
        int l=q[0], r=q[1], k=q[2], v=q[3];
        for(int i=l; i<=r; i+=k){
            long long x = nums[i];
            x *= v;
            nums[i] = x%mod;
        }
    }

    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        for(auto q : queries){
            fn(nums, q);
        }
        int res = 0;
        for(int x : nums) res ^= x;
        return res;
    }
};
