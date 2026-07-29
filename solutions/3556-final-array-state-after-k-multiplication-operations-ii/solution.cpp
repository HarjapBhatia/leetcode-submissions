#define mod 1000000007
typedef long long ll;
using P = pair<ll,int>;
class Solution {
public:
    ll modpow(ll a, ll b){
        ll ans = 1;
        while(b){
            if(b&1) ans = ans*a%mod;
            a = a*a%mod;
            b>>=1;
        }
        return ans;
    }

    vector<int> getFinalState(vector<int>& nums, int k, int mul) {
        int n=nums.size();

        if(mul==1) return nums;
        priority_queue<P, vector<P>, greater<P>> pq;
        ll mx = *max_element(nums.begin(), nums.end());
        for(int i=0;i<n;i++)
            pq.push({nums[i],i});

        while(k>0 && 1ll*pq.top().first*mul <= mx){
            auto [x,y] = pq.top(); pq.pop();
            x = 1ll*x*mul;
            pq.push({x,y});
            k--;
        }

        vector<int> res(n);
        int rep = k/n, rem = k%n;
        ll pow = modpow(mul, rep);

        while(!pq.empty()){
            auto [x,y] = pq.top(); pq.pop();
            ll v = (x%mod)*(pow%mod);
            if(rem){
                v = (v%mod)*(mul%mod); rem--;
            }

            res[y] = v%mod;
        }
        return res;
    }
};
