// idea: check for odd and even number of negatives
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int mx = nums[0], l=1, r=1;
        int n = nums.size();
        for(int i=0;i<n;i++){
            l *= nums[i];
            r *= nums[n-i-1];
            mx = max({mx, l, r});
            if(l==0) l=1;
            if(r==0) r=1;
        }
        return mx;
    }
};
