class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int m = mat.size(), n=mat[0].size(), cnt = 0;
        vector<int>r(m), c(n);
        for(int i=0;i<m;i++){
            int row_sm = 0;
            for(int j=0;j<n;j++){
                row_sm+=mat[i][j];
                c[j] += mat[i][j];
            }
            r[i] = row_sm;
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(mat[i][j]==1 && r[i]==1 && c[j]==1) cnt++;
            }
        }
        return cnt;
    }
};
