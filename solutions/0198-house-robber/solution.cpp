class Solution {
public:
    int rob(vector<int>& nums) {
        // method : 1 
        // int n=nums.size();
        // vector<int> dp(n,0);
        // dp[0] = nums[0];
        // if(n >= 2) dp[1] = max(nums[1], nums[0]);
        // for(int i=2;i<n;i++){
        //     dp[i] = max(dp[i-2]+nums[i], dp[i-1]);
        // }
        // return dp[n-1];

        //method : 2
        int p1=0, p2=0;
        for(int x: nums){
            int cur = max(p1, p2+x);
            p2 = p1;
            p1 = cur;
        }
        return p1;
    }
};
