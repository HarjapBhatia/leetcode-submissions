class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& bg) {
        int n = bg.size(), m=bg[0].size();
        for (auto &a : bg) {
            int j=m-1;
            for (int i=m-1;i>=0;i--) {
                if (a[i]=='*') j=i-1;
                else if (a[i] == '#') swap(a[i], a[j--]);
            }
        }
        vector<vector<char>> res(m, vector<char>(n));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++)
                res[j][n-i-1] = bg[i][j];
            
        }
        return res;
    }
};
