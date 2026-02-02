class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for(int i=0;i<n-1;i++){
            for(int j=i+1;j<n;j++){
                swap(matrix[i][j], matrix[j][i]);
                if(i == n/2 && j == n/2) return;
            }
        }
        for(auto &i : matrix) reverse(i.begin(), i.end());
    }
};
