class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int i=0, j=0, ix = 0;
        int n=mat.size(), m=mat[0].size();
        vector<int> res(n*m);
        while(ix < n*m){
            res[ix++] = mat[i][j];
            if((i+j)&1){    // downward movement, 3 cases
                if(i==n-1) j++; 
                else if(j==0) i++;
                else i++,j--;
            }else{  // upward movement, 3 cases
                if(j==m-1) i++;
                else if(i==0) j++;
                else i--, j++;
            }
        }
        return res;
    }
};
