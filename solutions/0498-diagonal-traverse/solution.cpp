class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int n=mat.size(), m=mat[0].size();
        int i=0, j=0, d=0;
        vector<int> res;

        // use seperate loops for every i+j check and then push back
        while(d < n*m){
            res.push_back(mat[i][j]); d++;
            if((i+j)%2==0){
                if(j==m-1) i++;
                else if(i==0) j++;
                else i--,j++;
            }else{
                if(i==n-1) j++;
                else if(j==0) i++;
                else i++,j--;
            }
        }
        return res;
    }
};
