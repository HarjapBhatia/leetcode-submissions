class Solution {
public:
    bool is(int x){
        if(x<=1 || (x%2==0 && x!=2)) return false;
        for(int i=3;i<=sqrt(x);i+=2){
            if(x%i==0) return false;
        }
        return true;
    }
    int sumOfPrimesInRange(int n) {
        int rev=0, m=n;
        while(m>0){
            rev = 10*rev+(m%10);
            m/=10;
        }
        int mi = min(rev,n), mx = max(rev,n);
        int sm=0;
        for(int i=mi;i<=mx;i++){
            if(is(i)) sm+=i;
        }
        return sm;
    }
};
