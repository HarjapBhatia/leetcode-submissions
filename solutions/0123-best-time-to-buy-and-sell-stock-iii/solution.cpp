class Solution {
public:
    int maxProfit(vector<int>& p) {
        int n = p.size();
        // when we do 0 txn, profit = 0
        int t0 = 0, t1 = 0, t2 = 0;

        // when we do only 1 txn
        // int mi=INT_MAX;
        // for(int x : p){
        //     mi = min(mi, x);
        //     t1 = max(0, x-mi);
        // }

        // when we do 2 txm (2 maximum stretches)
        vector<int> ltr(n,0), rtl(n,0);
        int fmi=p[0];
        for(int i=1;i<n;i++){
            fmi = min(fmi, p[i]);
            ltr[i] = max(ltr[i-1], p[i]-fmi);
        }
        int sma = p[n-1];
        for(int i=n-2;i>=0;i--){
            sma = max(sma, p[i]);
            rtl[i] = max(rtl[i+1], abs(sma - p[i]));
        }

        // ltr[n-1] and rtl[0] will be t1, we don't need extra loop for t1
        t1 = ltr[n-1];

        for(int i=0;i<n-1;i++){
            t2 = max(t2, ltr[i]+rtl[i+1]);
        }
        return max({t1,t2,t0});
    }
};
