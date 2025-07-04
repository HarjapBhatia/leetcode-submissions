class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int r, s=0, l=0, minL = INT_MAX, n = nums.size();
        
        for(r=0; r<n; r++){
            s += nums[r]; 
            while(s >= target){
                minL = min(minL,r-l+1);
                s -= nums[l];
                l++;
            }
        }   
        if(minL == INT_MAX) return 0;
        else return minL;
    }
};
