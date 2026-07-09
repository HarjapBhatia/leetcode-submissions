class Solution {
public:
    vector<vector<string>> res;
    vector<int> lrow, d1, d2;
    vector<string> board;

    void f(int col){
        int n=board.size();
        if(col == n){
            res.push_back(board); return;
        }

        for(int row=0;row<n;row++){
            if(!lrow[row] && !d1[row+col] && !d2[n-1+col-row]){
                board[row][col] = 'Q';
                lrow[row]=1;
                d1[row+col]=1;
                d2[n-1+col-row]=1;

                f(col+1);

                board[row][col] = '.';
                lrow[row]=0;
                d1[row+col]=0;
                d2[n-1+col-row]=0;
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        board.resize(n, string(n,'.'));
        lrow.resize(n,0);
        d1.resize(2*n-1, 0);
        d2.resize(2*n-1, 0);
        f(0);
        return res;
    }
};
