class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n=nums.size();
        unordered_map<int,int> fq;
        for(int i:nums) fq[i]++;
        if(k==1){
            int ans=-1;
            for(auto a : fq){
                if(a.second == 1) ans = max(ans,a.first);
            }
            return ans;
        }
        if(k==n){
            return *max_element(nums.begin(),nums.end());
        }
        if(fq[nums[0]]>1 && fq[nums[n-1]]>1) return -1;
        if(fq[nums[0]] > 1) return nums[n-1];
        if(fq[nums[n-1]] > 1) return nums[0];
        return max(nums[0],nums[n-1]);
    }
};
