class Solution {
public:
    int maxProduct(int n) {
        int f=-1,s=-1;
        while(n){
            int x=n%10;
            if(x>f) s=f,f=x;
            else if(x>s) s=x;
            n/=10;
        }
        return f*s;
    }
};
