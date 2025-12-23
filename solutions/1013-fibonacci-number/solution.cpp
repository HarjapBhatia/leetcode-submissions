class Solution {
public:
    int fib(int n) {
        if(n<2) return n;
        int prv1=0, prv=1;
        int cur = 0;
        for(int i=2; i<=n; i++){
            cur = prv+prv1;
            prv1 = prv;
            prv = cur;
        }
        return cur;
    }
};
