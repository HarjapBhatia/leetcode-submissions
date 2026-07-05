#define ll long long
class Solution {
public:
    vector<ll> ps;
    ll fsum(int l, int r){
        return ps[r] - (l>0 ? ps[l-1]:0);
    }
    long long getSum(vector<int>& nums) {
        int n=nums.size();
        ps.resize(n,0);
        ps[0]=nums[0];
        for(int i=1;i<n;i++) ps[i] = ps[i-1]+nums[i];

        vector<int> oo(n), ee(n);
        int l=0,r=-1;
        for(int i=0;i<n;i++){
            int k;
            if(i>r) k=1;
            else k = min(oo[l+r-i],r-i+1);
            while(i>=k && i<n-k && nums[i-k] == nums[i+k]) k++;
            oo[i]=k;
            if(i+k-1>r) {
                l=i-k+1; r=i+k-1;
            }
        }
        l=0,r=-1;
        for(int i=0;i<n;i++){
            int k;
            if(i>r) k=0;
            else k = min(ee[l+r-i+1],r-i+1);
            while(i>=k+1 && i<n-k && nums[i-k-1] == nums[i+k]) k++;
            ee[i]=k;
            if(i+k-1>r) {
                l=i-k; r=i+k-1;
            }
        }

        ll ans = LLONG_MIN;
        for(int i=0;i<n;i++){
            ans = max(ans, fsum(i-oo[i]+1, i+oo[i]-1));
        }
        
        for(int i=0;i<n;i++){
            if(ee[i]==0) continue;
            ans = max(ans, fsum(i-ee[i], i+ee[i]-1));
        }
        return ans;
    }
};
