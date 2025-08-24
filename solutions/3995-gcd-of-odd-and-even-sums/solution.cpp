class Solution {
public:
    int findGCD(int a, int b) {
        if (b == 0) return a;
        return findGCD(b, a % b);
    }
    int gcdOfOddEvenSums(int n) {
        int sumOdd = n * n;
        int sumEven = n * (n+1);
        return findGCD(sumOdd, sumEven);
    }
};
