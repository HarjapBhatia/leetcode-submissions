class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        vector<vector<int>> vec = img;
        int n = img.size(), m = img[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int sm = 0, cnt = 0;
                if(i-1 >= 0 && j-1 >= 0) sm += vec[i-1][j-1], cnt++;
                if(i+1<n && j+1<m) sm += vec[i+1][j+1], cnt++;
                if(i-1 >= 0 && j+1<m) sm += vec[i-1][j+1], cnt++;
                if(i+1 < n && j-1 >= 0) sm += vec[i+1][j-1], cnt++;
                
                if(i-1 >= 0) sm += vec[i-1][j], cnt++;
                if(j-1 >= 0) sm += vec[i][j-1], cnt++;
                if(i+1 < n) sm += vec[i+1][j], cnt++;
                if(j+1 < m) sm += vec[i][j+1], cnt++;
            
                sm += vec[i][j], cnt++;
                img[i][j] = (sm/cnt);
            }
        }
        return img;
    }
};
