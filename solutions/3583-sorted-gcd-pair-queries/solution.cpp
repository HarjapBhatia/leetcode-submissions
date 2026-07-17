class Solution {
public:
    // int gcd(int a, int b){ return b==0 ? a : gcd(b, a%b); }

    vector<int> gcdValues(vector<int>& nums, vector<long long>& queries) {
        int mx = *max_element(nums.begin(), nums.end());
        int n = nums.size();
        vector<long long> cnt(mx+1);
        for(int i : nums) cnt[i]++;
        
        for(int i=1;i<=mx;i++){
            for(int j=2*i; j<=mx; j+=i){
                cnt[i] += cnt[j];
            }
        }
        for(int i=1;i<=mx;i++){
            cnt[i] = cnt[i]*(cnt[i]-1)/2;
        }
        for(int i=mx;i>=1;i--){
            for(int j=2*i; j<=mx; j+=i){
                cnt[i] -= cnt[j];
            }
        }
        for(int i=1;i<=mx;i++){
            cnt[i] += cnt[i-1];
        }
        vector<int>ans;
        for(auto q : queries){
            int x = lower_bound(cnt.begin(), cnt.end(), q+1) - cnt.begin();
            ans.push_back(x);
        }

        return ans;
    }
};
