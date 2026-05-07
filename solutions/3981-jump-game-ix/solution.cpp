class Solution {
public:
    vector<int> maxValue(vector<int>& nums) {
        int n=nums.size();
        vector<int> s(n,0), p(n,0);
        p[0]=nums[0];
        for(int i=1;i<n;i++)
            p[i] = max(p[i-1], nums[i]);
        
        s[n-1]=nums[n-1];
        for(int i=n-2;i>=0;i--)
            s[i]=min(s[i+1], nums[i]);
        
        vector<int> ans(n);
        ans[n-1]=p[n-1];
        for(int i=n-2;i>=0;i--){
            if(p[i] > s[i+1]) ans[i] = ans[i+1];
            else ans[i] = p[i];
        }
        return ans;
    }
};
