class Solution {
public:
    int findGCD(vector<int>& nums) {
        int mx=-1, mi=10001;
        for(int i: nums){
            mx=max(mx,i); mi = min(mi,i);
        }
        return __gcd(mx, mi);
    }
};
