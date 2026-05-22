class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0, r= nums.size()-1;
        while(l<=r){
            int mi = (l+r)/2;
            if(nums[mi] == target) return mi;
            if(nums[l] <= nums[mi]){
                if(nums[l] <= target && target <= nums[mi]) r = mi-1;
                else l = mi+1;
            }else{
                if(nums[mi] <= target && target <= nums[r]) l = mi+1;
                else r = mi-1;
            }
        }
        return -1;
    }
};
