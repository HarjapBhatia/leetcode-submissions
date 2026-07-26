typedef long long ll;
class Solution {
public:
    string smallestGoodBase(string n) {
        ll x=stoll(n);
        for(int i=log2(x);i>=2;i--){
            ll k=pow(x,1.0/i);
            ll pr=1,sm=1;
            for(int j=1;j<=i;j++){
                pr *= k; sm += pr;
            }
            if(sm == x) return to_string(k);
        }
        return to_string(x-1);
    }
};
