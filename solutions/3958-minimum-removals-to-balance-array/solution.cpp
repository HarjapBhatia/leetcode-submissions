class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int i=0, ans = n;
        for(int j=0;j<n;j++){
            while(1ll * nums[i]*k < nums[j]) i++;
            ans = min(ans, n-(j-i+1));
        }   
        return ans;
    }
};
