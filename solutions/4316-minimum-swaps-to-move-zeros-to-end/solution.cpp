class Solution {
public:
    int minimumSwaps(vector<int>& nums) {
        int l=0,r=nums.size()-1;
        int cnt = 0;
        while(l<r){
            if(nums[r] == 0) {r--; continue;}
            if(nums[l] == 0){
                swap(nums[l], nums[r]);
                cnt++; r--;
            }
            l++;
        }
        return cnt;
    }
};
