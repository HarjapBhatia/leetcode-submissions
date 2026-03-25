class Solution {
public:
// note: there can't be two same values adjacent, so we can directly check on the right side of the mid, either it will be the wall element or the closest peak element to the right wall
    int findPeakElement(vector<int>& nums) {
        int l=0; int r = nums.size()-1;
        while(l<r){
            int mi = (l+r)/2;
            if(nums[mi] > nums[mi+1]) r=mi;
            else l=mi+1;
        }
        return l;
    }
};
