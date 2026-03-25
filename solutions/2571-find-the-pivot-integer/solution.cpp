class Solution {
public:
    int pivotInteger(int n) {
        int sm = (n*(n+1))/2;
        double x= sqrt(sm);
        if(x == ceil(x)) return (int)x;
        return -1;
    }
};
