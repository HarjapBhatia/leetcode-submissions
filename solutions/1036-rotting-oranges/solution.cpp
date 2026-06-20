class Solution {
public:
    int orangesRotting(vector<vector<int>>& g) {

        queue<pair<int,int>>q;
        int fresh=0;
        int m=g.size(), n=g[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(g[i][j]==1) fresh++;
                else if(g[i][j]==2) q.push({i,j});
            }
        }

        if(fresh==0) return 0;
        if(q.size()==0) return -1;
        int time=0;
            
        while(!q.empty()){
            int x=q.size();
            while(x--){
                int fi = q.front().first;
                int fj = q.front().second; q.pop();
                
                if(g[fi][fj]==0) continue;

                if(fi>0 && g[fi-1][fj]==1) {
                    g[fi-1][fj]=2; fresh--;
                    q.push({fi-1, fj});
                }
                if(fi<m-1 && g[fi+1][fj]==1){
                    g[fi+1][fj]=2; fresh--;
                    q.push({fi+1, fj});
                }
                if(fj>0 && g[fi][fj-1]==1) {
                    g[fi][fj-1]=2; fresh--;
                    q.push({fi, fj-1});
                }
                if(fj<n-1 && g[fi][fj+1]==1) {
                    g[fi][fj+1]=2; fresh--;
                    q.push({fi, fj+1});
                }

            }
            time++;
        }
        
        if(fresh!=0) return -1;
        return time-1 ;
    }
};
