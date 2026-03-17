class Solution {
public:
    int trailingZeroes(int n) {
        // if(n==0) return 0;
        int cnt =0;
        int x = 5;
        while(x <= n){
            cnt += (n/x);
            x *= 5;
        }
        return cnt;
    }
};
