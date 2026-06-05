class Solution {
typedef long long ll;
public:
    int maximumCandies(vector<int>& c, long long k) {
        ll l=1, r=*max_element(c.begin(), c.end());
        ll ans =0;
        while(l<=r){
            ll mi = l+(r-l)/2;
            ll cnt =0;
            for(int i : c) cnt += (i/mi);

            if(cnt >= k){
                ans=mi; 
                l=mi+1;
            }else{
                r=mi-1;
            }
        }

        return (int) ans;
    }
};
