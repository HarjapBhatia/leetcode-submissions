class Solution {
public:
    int arrangeCoins(int n) {
        int l=0, r=n;
        while(l<=r){
            int m = (l+r)/2;
            long long t = (long long)(m+1)*m/2;
            if(t == n) return m;
            else if(t > n) r = m-1;
            else l=m+1;
        }
        return r;
    }
};
