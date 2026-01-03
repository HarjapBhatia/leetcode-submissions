class Solution {
public:
    int minLength(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int,int> freq;
        long long sm = 0;
        int l = 0, ans = INT_MAX;
        for(int r=0;r<n;r++){
            if(freq[nums[r]] == 0) sm += nums[r];
            freq[nums[r]]++;
            
            while(sm >= k){
                ans = min(ans, r-l+1);
                freq[nums[l]]--;
                if(freq[nums[l]] == 0) sm -= nums[l];
                l++;
            }
        }
        return ans == INT_MAX ? -1 : ans;
    }
};
