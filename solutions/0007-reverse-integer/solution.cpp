#include<climits>
class Solution {
public:
    int reverse(int x) {
        int s = 0;
        while(x != 0){
            int rem = x%10;

            if (s > INT_MAX / 10 || s < INT_MIN / 10) return 0;

            s = 10*s + rem;
            x/=10;
        }
        return s;
    }
};
