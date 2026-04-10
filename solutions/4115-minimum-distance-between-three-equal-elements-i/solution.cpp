class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        int ans = 1e6, n = nums.size();
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                for(int k=j+1;k<n;k++){
                    if(nums[i] == nums[j] && nums[i] == nums[k]){
                        int x = abs(j-i)+abs(k-j)+abs(k-i);
                        ans = min(ans, x);
                    }
                }
            }
        }
        return ans==1e6 ? -1 : ans;
    }
};
