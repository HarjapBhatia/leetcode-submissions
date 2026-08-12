class Solution {
public:  
    int maxSubarrayLength(vector<int>& nums, int k) {
        unordered_map<int,int> fq;
        int n=nums.size(),ans=0,l=0,r=0;
        for(r=0;r<n;r++){
            fq[nums[r]]++;
            while(fq[nums[r]]>k){
                fq[nums[l]]--; l++;
            }
            ans = max(ans, r-l+1);
        }
        return ans;
    }
};
