class Solution {
public:
    // bool bs(vector<int>&vec,int tg){
    //     int l=0, r=vec.size()-1;
    //     while(l<=r){
    //         int m = (l+r)/2;
    //         if(vec[m] == tg) return true;
    //         else if(tg < vec[m]) r=m-1;
    //         else l=m+1;
    //     }
    //     return false;
    // }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        // method-1
        int m = matrix.size();
        int n = matrix[0].size();

        // int s=0, e=m-1;
        // while(s<=e){
        //     int mi = s+ (e-s)/2;
        //     if(target < matrix[mi][0]) e=mi-1;
        //     else if(target > matrix[mi][n-1]) s=mi+1;
        //     else{
        //         return bs(matrix[mi], target);
        //     }
        // }
        // return false;

        // method-2
        // let n = no. of cols, so..
        // row = idx/n and col = idx%n;
        // make this to single array
        
        int l=0, r=n*m-1;
        while(l<=r){
            int mi = l+(r-l)/2;
            int x = matrix[mi/n][mi%n];
            if(x == target) return true;
            else if(x < target) l=mi+1;
            else r=mi-1;
        }
        return false;
    }
};
