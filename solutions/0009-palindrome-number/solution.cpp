class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0) return false;
        int n = x;
        long long res = 0;
        while(x > 0){
            res = 10*res + (x%10);
            x/=10;
        }
        return res == n;
    }
};
