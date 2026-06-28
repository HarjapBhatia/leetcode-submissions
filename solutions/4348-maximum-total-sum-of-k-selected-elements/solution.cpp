class Solution {
public:
    long long maxSum(vector<int>& nums, int k, int mul) {
        sort(nums.begin(), nums.end());
        int n=nums.size();
        long long ans=0;
        for(int i=n-1;i>=n-k;i--){
            if(mul != 0){
                ans += 1ll*nums[i]*mul; mul--;
            }else{
                ans += nums[i];
            }
        }
        return ans;
    }
};
