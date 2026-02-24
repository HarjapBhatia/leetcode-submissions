class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mi = INT_MAX;
        int prof = 0;
        for(int x: prices){
            mi = min(mi, x);
            prof = max(prof, x-mi);
        }
        return prof;
    }
};
