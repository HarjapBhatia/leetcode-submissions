class Solution {
public:
    int maxIceCream(vector<int>& c, int coins) {
        int mx = *max_element(c.begin(), c.end());
        vector<int> cnt(mx+1,0);
        for(int i : c) cnt[i]++;
        int ans =0;

        for(int i=1;i<=mx;i++){
            int can = min(coins/i, cnt[i]);
            ans += can;
            coins -= can*i;
        }
        return ans;
    }
};
