class Solution {
public:
    // vector<vector<int>> dirs = {{1,0}, {-1,0}, {0,1}, {0,-1}};
    // bool isvalid(vector<vector<int>> &image, int x, int y){
    //     return x>=0 && x<image.size() && y>=0 && y<image[0].size();
    // }
    int og;

    void dfs(vector<vector<int>>&img, int sr, int sc, int color){
        if(!(sr >=0 && sr<img.size() && sc>=0 && sc<img[0].size())) return;
        if(img[sr][sc] != og) return;
        img[sr][sc] = color;
        dfs(img, sr+1, sc, color);
        dfs(img, sr-1, sc, color);
        dfs(img, sr, sc-1, color);
        dfs(img, sr, sc+1, color);
    }
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {

        og = image[sr][sc];
        if(og == color) return image;
        dfs(image, sr, sc, color);
        return image;

        // int m=image.size(), n=image[0].size();
        // int prev = image[sr][sc];
        // image[sr][sc] = color;
        // queue<pair<int,int>> q;
        // vector<vector<bool>> vis(m,vector<bool>(n, false));
        // q.push({sr,sc}); vis[sr][sc] = true;
            
        // while(!q.empty()){
        //     auto [x, y] = q.front(); q.pop();
        //     for(auto &d : dirs){
        //         int dx = x+d[0], dy=y+d[1];
        //         if(isvalid(image,dx,dy) && image[dx][dy]==prev){
        //             if(!vis[dx][dy]){
        //                 image[dx][dy] = color;
        //                 vis[dx][dy] = true;
        //                 q.push({dx,dy});
        //             }
        //         }
        //     }
        // }
        // return image;
    }
};
