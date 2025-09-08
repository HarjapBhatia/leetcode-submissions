class Solution {
public:
    int haszero(int n){
        while(n!=0){
            int rem = n%10;
            if(rem == 0) return true;
            n/=10;
        }
        return false;
    }
    vector<int> getNoZeroIntegers(int n) {
        vector<int> ans(2);
        for(int i=1;i<n;i++){
            int a = i;
            int b = n-i;
            if(!haszero(a) && !haszero(b)){
                ans[0] = a;
                ans[1] = b;
            }
        }
        return ans;
    }
};
