typedef long long ll;
using T = tuple<ll,int,int,int>; 

class Solution {
public:
    long long minCost(int m, int n, vector<vector<int>>& penalty) {
        const ll INF = 1e18;
        vector<vector<vector<ll>>> 
            dist(m, vector<vector<ll>>(n, vector<ll>(2, INF)));

        priority_queue<T, vector<T>, greater<T>> pq;

        dist[0][0][1] = 1; // entering cost 0,0
        pq.push({1,0,0,1}); 

        int dx[4]={0,1,0,-1};
        int dy[4]={1,0,-1,0};

        while(!pq.empty()){

            auto [d,x,y,p]=pq.top(); // cur_dist, x, y, parity
            pq.pop();

            if(d!=dist[x][y][p]) continue;

            if(x==m-1 && y==n-1) return d;

            if(d + penalty[x][y] < dist[x][y][p^1]){
                dist[x][y][p^1] = d + penalty[x][y];
                pq.push({dist[x][y][p^1],x,y,p^1});
            }

            for(int k=0;k<4;k++){

                int nx=x+dx[k];
                int ny=y+dy[k];
                if(nx<0||nx>=m||ny<0||ny>=n) continue;

                ll add=(ll)(nx+1)*(ny+1);

                bool is=false;

                if(p){
                    if((dx[k]==0 && dy[k]==1) || (dx[k]==1 && dy[k]==0))
                        is=true;
                }else{ 
                    if((dx[k]==0 && dy[k]==-1) || (dx[k]==-1 && dy[k]==0))
                        is=true;
                }

                if(!is)
                    add += penalty[x][y];

                if(d+add < dist[nx][ny][p^1]){
                    dist[nx][ny][p^1] = d + add;
                    pq.push({dist[nx][ny][p^1], nx, ny, p^1});
                }
            }
        }

        return -1;
    }
};
