class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int n = nums.size();
        vector<int> f(n,0); 
        int sm = 0;
        for(int i=0;i<n;i++) {f[0] += (i*nums[i]); sm+=nums[i];}
        // cuz the state is, f(k) = f(k-1)+ sm - (n*nums[n-k])
        int ans = f[0];
        for(int i=1;i<n;i++){
            f[i] = f[i-1] + sm - n*nums[n-i];
            ans = max(ans, f[i]);
        }
        return ans;
    }
};
