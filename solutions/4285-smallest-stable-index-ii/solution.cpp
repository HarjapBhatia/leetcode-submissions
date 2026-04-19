class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int> sm(n);
        sm[n-1] = nums[n-1];
        // int mi = sm[n-1];
        for(int i=n-2;i>=0;i--){
            sm[i] = min(nums[i], sm[i+1]);
        }
        int mx = 0;
        for(int i=0;i<n;i++){
            mx = max(mx, nums[i]);
            if(mx - sm[i] <= k) return i;
        }
        return -1;
    }
};
