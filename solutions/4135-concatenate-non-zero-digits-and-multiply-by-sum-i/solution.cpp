class Solution {
public:
    long long sumAndMultiply(int n) {
        long long sum=0;
        int i=0, x=0;
        while(n>0){
            int rem = n%10;
            sum+=rem%10;
            if(rem>0){
                x = pow(10,i)*rem + x;
                i++;
            }
            n/=10;
        }
        return (long long) sum*x;
    }
};
