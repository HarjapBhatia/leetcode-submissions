class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        int n=nums.size();
        long long sm = accumulate(nums.begin(),nums.end(),0ll);
        
        int tg = sm%p, ans=n;
        if(!tg) return 0;

        unordered_map<long long, int> s;
        long long ps=0;
        s[0]=-1;
        for(int i=0;i<n;i++){
            ps += nums[i];
            if(s.find((ps-tg+p)%p) != s.end()){
                int x = s[(ps-tg+p)%p];
                ans = min(ans, abs(x-i));
            }
            s[ps%p] = i;
        }

        return ans==n ? -1 : ans;
    }
};
