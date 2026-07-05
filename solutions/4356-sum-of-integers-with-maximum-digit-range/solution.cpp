class Solution {
public:
    int maxDigitRange(vector<int>& nums) {
        int n=nums.size();
        vector<int> cnt(10,0);
        for(int i : nums){
            int mx=-1, mi=10;
            int x=i;
            while(i>0){
                mx=max(mx,i%10);
                mi=min(mi,i%10);
                i/=10;
            }
            cnt[mx-mi] += x;
        }
        for(int i=9;i>=0;i--){
            if(cnt[i] > 0) return cnt[i];
        }
        return -1;
    }
};
