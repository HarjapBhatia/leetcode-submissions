class Solution {
public:
    int f(vector<int>&nums, int k){
        if(k<0) return 0;
        unordered_map<int,int> fq;
        int n=nums.size(),cnt=0,j=0;
        for(int i=0;i<n;i++){
            fq[nums[i]]++;
            while(fq.size() > k){
                fq[nums[j]]--;
                if(!fq[nums[j]]) fq.erase(nums[j]);
                j++;
            }
            cnt += i-j+1;
        }
        return cnt;
    }

    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return f(nums,k)-f(nums,k-1);
    }
};
