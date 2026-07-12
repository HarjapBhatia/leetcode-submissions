#define mod 1000000007
class Solution {
public:
    int minimumCost(vector<int>& nums, int k) {
        int n=nums.size();
        long long x=k, cnt=0;
        sort(nums.begin(),nums.end());
        for(int i=0;i<n;i++){
            if(x >= nums[i]) x -= nums[i];
            else{
                long long inc = (nums[i]+k-1-x)/k;
                cnt += inc;
                x += (inc*k) - nums[i]; 
            }            
        }
        long long ans = (1ll * (cnt%mod) * ((cnt+1)%mod))/2;

        return ans%mod;
    }
};
