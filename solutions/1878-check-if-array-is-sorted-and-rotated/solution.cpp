class Solution {
public:
    bool check(vector<int>& nums) {
        // if the array is already sorted there will be no drop
        // else if there is a rotation, there should be atlest one drop of 
        //value where nums[i-1] > nums[i], if it is more than 1 then it isfalse
        // in case of rotation we have to make sure if the last value is 
        //  greater or less than first value
        int cnt=0;
        for(int i=1;i<nums.size();i++){
            if(nums[i-1] > nums[i]) cnt++;
        }
        if(nums[0] < nums[nums.size()-1]) cnt++;
        return cnt <= 1;
    }
};
