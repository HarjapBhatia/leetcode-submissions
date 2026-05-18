class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        for(int &i : nums) i *= i;
        vector<int> vec(n);
        int i=0,j=n-1;
        int k=n-1;
        while(i<=j){
            if(nums[i] <= nums[j]) vec[k--] = nums[j--];
            else vec[k--] = nums[i++]; 
        }
        
        return vec;
    }
};
