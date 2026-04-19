class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size(); 
        for(int i=0;i<n;i++){
            int mx=0, mi=1e9;
            for(int w=0;w<=i;w++) mx = max(mx, nums[w]);
            for(int w=i;w<n;w++) mi = min(mi, nums[w]);
            if(mx-mi <= k) return i; 
        }
        return -1;
    }
};
