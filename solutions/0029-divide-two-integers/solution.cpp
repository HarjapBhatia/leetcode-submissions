class Solution {
public:
    int divide(int dividend, int divisor) {
        if(dividend > INT_MAX) return INT_MAX;
        else if(dividend < INT_MIN) return INT_MIN;
        else if (dividend == INT_MIN && divisor == -1) return INT_MAX;
        else return dividend / divisor;
    }
};
