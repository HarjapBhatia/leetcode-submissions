class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> res(n,vector<int>(n));
        int x = 1, tp=0, lf=0, rg = n-1, bt = n-1;
        while(tp <= bt && lf <= rg){
            for(int i=lf; i<=rg; i++) res[tp][i] = x++;
            tp++;
            for(int i=tp; i<=bt; i++) res[i][rg] = x++;
            rg--;
            if(tp <= bt){
                for(int i=rg; i>= lf; i--) res[bt][i] = x++;
                bt--;
            }
            if(lf <= rg){
                for(int i=bt; i>=tp; i--) res[i][lf] = x++;
                lf++;
            }
        }
        return res;
    }
};
