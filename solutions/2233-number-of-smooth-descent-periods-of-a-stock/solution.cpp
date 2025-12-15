class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {
        long long cnt = 1, idx=1;
        int n = prices.size();
        for(int i=1;i<n;i++){
            (prices[i]-prices[i-1] == -1) ? idx++ : idx=1;
            cnt += idx;
        }
        return cnt;
    }
};
