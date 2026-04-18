class Solution {
public:
    int mirrorDistance(int n) {
       int x=n,r=0;
       while(x>0){
        r = 10*r + x%10;
        x/=10;
       } 
       return abs(r-n);
    }
};
