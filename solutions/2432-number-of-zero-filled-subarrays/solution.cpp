class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long cnt = 0;
        long long st = 0;
        for(long long i=0; i<nums.size(); i++){
            if(nums[i] == 0){
                st++;
                cnt += st;
            }else{
                st = 0;
            }
        }
        return cnt;
    }
};
