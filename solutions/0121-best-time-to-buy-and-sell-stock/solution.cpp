class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mi = INT_MAX;
        int mxp = 0;
        for(int x : prices) {
            mi = min(mi, x);               
            mxp = max(mxp, x - mi);  
        }
        return mxp;

    }
};
