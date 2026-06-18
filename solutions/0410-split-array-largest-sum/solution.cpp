class Solution {
public:
    bool is(vector<int> &nums, int mi, int k){
        int cur=0, cnt=1;
        for(int i : nums){
            if(i > mi) return false;
            if(i+cur > mi){
                cnt++; cur = i;
            }else cur += i;
        }
        return cnt <= k;
    }
    int splitArray(vector<int>& nums, int k) {
        int l=*min_element(nums.begin(), nums.end());
        int r=accumulate(nums.begin(), nums.end(), 0);
        int ans = -1;
        while(l<=r){
            int mi = l+(r-l)/2;
            if(is(nums, mi, k)){
                ans = mi; r=mi-1;
            }else l=mi+1;
        }
        return ans;
    }
};
