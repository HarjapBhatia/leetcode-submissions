class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        int l = 0, r = n-1;
        while(l<=r){
            int m = (l+r)/2;
            if(m+1<n && nums[m]==nums[m+1]){
                m&1 ? r=m-1 : l=m+2;
            }
            else if(m-1 >= 0 && nums[m] == nums[m-1]){
                m&1 ? l=m+1 : r=m-2;
            }
            else return nums[m];
        }
        return -1;
    }
};
