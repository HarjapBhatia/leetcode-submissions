class Solution {
public:
    long long minArraySum(vector<int>& nums) {
        int n=nums.size();
        int mx = *max_element(nums.begin(), nums.end());
        vector<bool> is(mx+1, false);
        for(int x : nums) is[x] = true;
        vector<int> ans(mx+1,0);
        for(int d=1;d<=mx;d++){
            if(!is[d]) continue;
            for(int i=d;i<=mx;i+=d){
                if(ans[i]==0) ans[i] = d;
            }
        }
        long long res=0;
        for(int x : nums) res += ans[x];
        return res;
    }
};
