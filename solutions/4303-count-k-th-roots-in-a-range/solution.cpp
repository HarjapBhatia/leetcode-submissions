class Solution {
public:
    long long power(long long a, int k) {
        long long res = 1;
        while (k--) res *= a;
        return res;
    }
    int countKthRoots(int l, int r, int k) {
        long long a = ceil(pow(l, 1.0/k));
        long long b = floor(pow(r, 1.0/k));

        while (a > 0 && power(a - 1, k) >= l) a--;
        while (power(b + 1, k) <= r) b++;

        return b-a+1;
    }
};
