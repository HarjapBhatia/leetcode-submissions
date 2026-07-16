class Solution {
public:
    int gcd(int a, int b){
        return b==0 ? a : gcd(b, a%b);
    }
    long long gcdSum(vector<int>& nums) {
        int n=nums.size();
        vector<int> pg(n);
        int mx = nums[0];
        pg[0] = gcd(nums[0], mx);
        for(int i=1;i<n;i++){
            mx = max(mx, nums[i]);
            pg[i] = gcd(mx, nums[i]);
        }
        sort(pg.begin(),pg.end());
        long long ans=0;
        int l=0, r=n-1;
        while(l<r){
            ans += gcd(pg[l++], pg[r--]);
        }
        return ans;
    }
};
