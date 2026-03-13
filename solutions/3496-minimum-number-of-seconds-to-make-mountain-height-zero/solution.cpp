class Solution {
typedef long long ll;
public:
    long long minNumberOfSeconds(int mht, vector<int>& wt) {
        ll l=1, h=1e16;
        while(l<h){
            ll mi = (l+h)/2;
            ll tot = 0;
            for(ll i=0;i<wt.size();i++){
                if(tot >= mht) break;
                tot += (sqrt((2*mi/wt[i]) + 0.25) - 0.5);
            }
            if(tot >= mht) h = mi;
            else l = mi+1;
        }
        return l;
    }
};
