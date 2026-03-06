class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> hsh;
        int n = nums.size();
        long long sm = 0;
        int p=0;
        for(int i=0;i<n;i++){
            sm += nums[i];
            if(hsh[sm%k] > 0) return true;
            hsh[p]++;   // storing the previous remainder
            p = sm%k;   
        }
        return false;
    }
};
