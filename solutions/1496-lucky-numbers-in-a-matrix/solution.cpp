class Solution {
public:
    vector<int> luckyNumbers(vector<vector<int>>& matrix) {
        int mxr = 0, mij = 0;
        for(int i=0;i<matrix.size();i++){
            int mic = 1e5+1;
            for(int j=0;j<matrix[0].size();j++){
                if(matrix[i][j] < mic) mic = matrix[i][j], mij = j;
            }
            mxr = max(mxr, mic);
        }
        int tmx = 0;
        for(int i=0;i<matrix.size();i++) tmx = max(tmx, matrix[i][mij]);
        if(tmx > mxr) return{};
        return {mxr};
    }
};
