class Solution {
public:
    bool isval(vector<vector<char>>&b, int r, int c, char v){
        for(int i=0;i<9;i++){
            if(b[i][c] == v || b[r][i] == v) return false;
        }
        int ro = (r/3)*3, co = (c/3)*3;
        for(int k=ro;k<ro+3;k++){
            for(int l=co;l<co+3;l++){
                if(b[k][l] == v) return false;
            }
        }
        return true;
    }

    bool f(vector<vector<char>> &b){

        for(int r=0;r<9;r++){
            for(int c=0;c<9;c++){
              
                if(b[r][c] == '.'){
                    for(char k='1';k<='9';k++){
                        if(isval(b,r,c,k)){
                            b[r][c] = k;
                            if(f(b)) return true;
                            b[r][c] = '.';
                        }
                    }
                    return false;
                }
              
            }
        }
        return true;
        
    }

    void solveSudoku(vector<vector<char>>& b) {
        f(b);    
    }
};
