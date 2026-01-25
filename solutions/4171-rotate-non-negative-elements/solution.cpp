class Solution {
public:
    void rotate(vector<int>&vec, int k){
        if(vec.size() == 0) return;
        k= k%vec.size();
        reverse(vec.begin(), vec.begin()+k);
        reverse(vec.begin()+k, vec.end());
        reverse(vec.begin(), vec.end());
    }

    vector<int> rotateElements(vector<int>& nums, int k) {
        vector<int> vec, res(nums.size());
        for(int x:nums){
            if(x >= 0) vec.push_back(x);
        }
        rotate(vec, k);
        int j=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]<0) res[i] = nums[i];
            else res[i] = vec[j++]; 
        }
        return res;
    }
};
