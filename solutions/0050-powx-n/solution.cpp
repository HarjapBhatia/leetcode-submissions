class Solution {
public:
    double myPow(double x, int n) {
        double res = 1.0;
        long long exp = n;
        if(exp<0){
            x = 1/x;
            exp = -exp;
        }
        while(exp>0){
            if(exp & 1) res *= x;
            x *= x;
            exp >>= 1;   
        }
        return res;
    }
};
