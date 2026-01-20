class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        for(int &x : nums){
            if(x%2 == 0) x = -1;
            else{
                int i=0;
                while(x & (1<<i)) i++;
                x ^= 1 << (i-1);
            }
        }
        return nums;
    }
};
