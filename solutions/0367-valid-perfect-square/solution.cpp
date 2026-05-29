class Solution {
public:
    bool isPerfectSquare(int num) {
        int l=0, r=num;
        while(l<=r){
            int m = (l+r)/2;
            long long sq = (long long)m*m;
            if(sq == num) return true;
            else if(sq > num) r=m-1;
            else l=m+1;
        }
        return false;
    }
};
