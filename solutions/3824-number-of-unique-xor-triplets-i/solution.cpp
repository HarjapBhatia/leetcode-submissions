class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n = nums.size();
        if(n<=2) return n;

        int msb=0;
        while(n){
            n>>=1;
            msb++;
        }
        return (1<<msb);
    }
};
