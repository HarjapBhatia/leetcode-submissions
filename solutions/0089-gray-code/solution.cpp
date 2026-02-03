class Solution {
public:
    void fn(int n, vector<int>&res, vector<bool> &is, int x){
        if(res.size() == (1<<n)) return;
        for (int i=0; i<n; i++) {
            int nxt = x^(1<<i);
            if (!is[nxt]) {
                is[nxt] = true;
                res.push_back(nxt);
                fn(n,res,is,nxt);
                return;
            }
        }
    }

    vector<int> grayCode(int n) {
        int cnt = 0;
        vector<int>res;
        vector<bool>is(1<<n, false);
        res.push_back(0);
        is[0] = true;
        fn(n, res, is, 0);
        return res;
    }
};
