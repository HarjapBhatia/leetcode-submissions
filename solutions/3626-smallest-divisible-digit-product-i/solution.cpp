class Solution {
public:
    int smallestNumber(int n, int t) {

        for(int i=n;i<=101;i++){
            int pr=1, x=i;
            while(x){
                pr *= x%10; x/=10;
            }
            if(pr%t == 0) return i;
        }
        return -1;
    }
};
