class Solution {
public:
    float getDiag(int len, int bre) {
        return sqrt(len * len + bre * bre);
    }

    int getArea(int len, int bre) {
        return len * bre;
    }

    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        int mx_area = 0;
        float mx_diag = 0.0;
        for (int i = 0; i < dimensions.size(); i++) {
            float curr_diag = getDiag(dimensions[i][0], dimensions[i][1]);
            int curr_area = getArea(dimensions[i][0], dimensions[i][1]);

            if (curr_diag > mx_diag) {
                mx_diag = curr_diag;
                mx_area = curr_area;
            } 
            else if (curr_diag == mx_diag) {
                mx_area = max(mx_area, curr_area);
            }
        }
        return mx_area;
    }
};

