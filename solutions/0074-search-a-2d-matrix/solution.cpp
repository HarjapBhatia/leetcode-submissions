class Solution {
public:
    // bool bs(vector<int> vec, int l, int r, int tg){
    //     while(l<r){
    //         int m = (l+r)/2;
    //         if(vec[m] == tg) return true;
    //         else if(vec[m] > tg) l=m+1;
    //         else r=m-1;
    //     }
    //     return false;
    // }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
       int m = matrix.size();
       int n = matrix[0].size();
       int i=0, j=n-1;
       while(i<m && j>=0){
        if(matrix[i][j] == target) return true;
        else if(matrix[i][j] > target) j--;
        else i++;
       }
       return false;
    }
};
