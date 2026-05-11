class Solution {
public:
    vector<int> res;
    void f(int x){
        while(x>0){
            res.push_back(x%10);
            x/=10;
        }
    }
    vector<int> separateDigits(vector<int>& nums) {
        for(int i=nums.size()-1; i>=0; i--) f(nums[i]);
        reverse(res.begin(), res.end());
        return res;
    }
};
