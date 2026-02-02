class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        int l=0, r=m-1, t=0, b=n-1;
        vector<int> res;
        while(l<=r && t<=b){
            for(int k=l;k<=r;k++) res.push_back(matrix[t][k]);
            t++;
            for(int k=t;k<=b;k++) res.push_back(matrix[k][r]);
            r--;
            
            if(t<=b){
                for(int k=r;k>=l;k--) res.push_back(matrix[b][k]);
                b--;
            }
            if(l<=r){
                for(int k=b;k>=t;k--) res.push_back(matrix[k][l]);
                l++;
            }

        }
        return res;
    }
};
