class Solution {
public:
    int maxJumps(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> dp(n,1);
        vector<pair<int,int>> vec; 
            
        for(int i=0;i<n;i++){
            vec.push_back({nums[i],i});
        }
        // Smaller elements ko pehle process karenge,
        // taaki larger element ka dp calculate krte time
        // smaller elements ka dp already available ho
        sort(vec.begin(), vec.end());

        for(auto &it : vec){
            int i = it.second;
            
            for(int j=i-1;j>=max(0,i-k);j--){
                if(nums[j]>=nums[i]) break;
                dp[i] = max(dp[i], 1+dp[j]);
            }
            
            for(int j=i+1;j<=min(n-1,i+k);j++){
                if(nums[j]>=nums[i]) break;
                dp[i] = max(dp[i], 1+dp[j]);
            }
        }
        return *max_element(dp.begin(), dp.end());
    }
};
