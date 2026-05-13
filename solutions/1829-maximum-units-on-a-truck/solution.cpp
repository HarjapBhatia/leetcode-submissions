class Solution {
public:
    int maximumUnits(vector<vector<int>>& bt, int ts) {
        int n=bt.size();
        // for(auto &a : bt) swap(a[0], a[1]);
        // sort(bt.rbegin(), bt.rend());
        sort(bt.begin(), bt.end(), [](vector<int>&a, vector<int>&b){
            return a[1] > b[1];
        });
        int ans=0;
        for(auto a : bt){
            int x = min(a[0], ts);
            ans += (x * a[1]);
            ts -= x;
        }
        return ans;
    }
};
