class Solution {
public:
    int sumdigit(int n){
        int sm = 0;
        while(n>0){
            sm += (n%10);
            n/=10;
        }
        return sm;
    }
    int smallestIndex(vector<int>& nums) {
        for(int i=0;i<nums.size();i++){
            if(nums[i] > 9) nums[i] = sumdigit(nums[i]);
            if(nums[i] == i) return i;
        }
        return -1;
    }
};
