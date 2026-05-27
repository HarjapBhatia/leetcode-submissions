class Solution {
public:
    int countPairs(vector<int>& nums, int k) {
        int cnt = 0, n=nums.size();
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                if(i==j) continue;
                if(nums[i]==nums[j] && (i*j)%k==0) cnt++;
            }
        }
        return cnt;
    }
};
