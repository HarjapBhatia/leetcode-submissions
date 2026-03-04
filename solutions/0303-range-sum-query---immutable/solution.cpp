class NumArray {
private:
    vector<int> p_sum;
public:
    NumArray(vector<int>& nums) {
        p_sum.resize(nums.size());
        p_sum[0] = nums[0];
        for(int i=1;i<nums.size();i++) p_sum[i] = p_sum[i-1]+nums[i];
    }
    
    int sumRange(int left, int right) {
        if(left == 0) return p_sum[right];
        return p_sum[right]-p_sum[left-1];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */
