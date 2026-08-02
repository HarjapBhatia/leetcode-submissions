class Solution {
public:
    int countRatioSubarrays(vector<int>& nums, int a, int b) {
        int n=nums.size();
        vector<int> codd(n+1, 0);
        for(int i=0;i<n;i++){
            codd[i+1] = codd[i] + (nums[i]&1);
        }
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<=i;j++){
                int cnt_odd = codd[i+1]-codd[j];
                int cnt_eve = i-j+1-cnt_odd;
                if(cnt_odd > 0) 
                    if(b*cnt_eve <= a*cnt_odd) ans++;
            }
        }
        return ans;
    }
};
