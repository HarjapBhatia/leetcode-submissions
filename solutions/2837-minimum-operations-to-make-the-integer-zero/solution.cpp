class Solution {
public:
    int makeTheIntegerZero(int num1, int num2) {
        for(int k=0;k<=60;k++){
            long long res = (long long)num1 - (long long)k*num2;
            int bits = __builtin_popcountll(res);
            if(bits <= k && k<=res) return k;
        }
        return -1; 
    }
};
