class Solution {
public:
    int n,m;
    vector<int> x = {0,0,1,-1}, y={1,-1,0,0};
    bool is(int xx, int yy){ return xx>=0 && xx<n && yy>=0 && yy<m; }

    bool f(int i, int j, int wi, string w, vector<vector<char>>&b){
        if(b[i][j] != w[wi]) return false;
        if(wi == w.size()-1) return true;
        char tmp = b[i][j];
        b[i][j] = '$';
        for(int k=0;k<4;k++){
            int ni = i+x[k], nj = j+y[k];
            if(is(ni,nj) && b[ni][nj] != '$'){
                if(f(ni,nj,wi+1,w,b)){
                    b[i][j]=tmp; return true;
                }
            }
        }
        b[i][j] = tmp;
        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        n=board.size(),m=board[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j] == word[0]){
                    if(f(i,j,0,word,board)) 
                        return true; 
                }
            }
        }
        return false;
    }
};
