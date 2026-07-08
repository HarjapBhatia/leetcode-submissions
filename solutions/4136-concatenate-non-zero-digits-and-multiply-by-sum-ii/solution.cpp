#define mod 1000000007
#define MX 100001
#define ll long long

ll p10[MX];
int fn = [](){
    p10[0]=1;
    for(int i=1;i<MX; i++) p10[i] = (p10[i-1]*10)%mod;

    return 0;
}();

class Solution {
public:
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        int n=s.size();
        vector<ll> sum(n), x(n), cnt(n);

        sum[0] = x[0] = s[0]-'0';
        cnt[0] = (x[0] > 0);
        for(int i=1;i<n;i++){
            int dig = s[i]-'0';
            cnt[i] = cnt[i-1] + (dig>0);
            sum[i] = sum[i-1] + dig;
            x[i] = (dig>0 ? (10*x[i-1]+dig)%mod: x[i-1]); 
        }

        vector<int> res;
        for(auto q : queries){
            int l = q[0], r=q[1];
            if(l==0){
                res.push_back((sum[r]*x[r])%mod);
                continue;
            }

            int len = cnt[r]-cnt[l-1];
            ll v1 = sum[r] - sum[l-1];
            ll mul = p10[len];
            // the integer can overflow (can go -ve). thus, do (+ mod)
            ll v2 = x[r] - (x[l-1]*mul)%mod + mod; 
            res.push_back((v1*v2)%mod);
        }
        return res;
    }
};
