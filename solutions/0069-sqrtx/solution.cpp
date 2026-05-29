class Solution {
public:
    int mySqrt(int x) {
        int l=0, r=x;
        // int ans = x;
        if(x==0 || x==1) return x;
        // while(l<=r){
        //     int m = (l+r)/2;
        //     if(m > x/m) {ans = m; r=m-1;}
        //     else l=m+1;
        // }
        // return ans-1;
        while(l<=r){
            int m = (l+r)/2;
            long long sq = (long long)m*m;
            if(sq == x) return m;
            else if(sq > x) r=m-1;
            else l=m+1;
        }
        return r;
    }
};
