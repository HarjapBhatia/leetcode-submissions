using pii = pair<int,int>;
class Solution {
public:
    vector<vector<int>> vec;
    int m=0,n=0,x=0,y=0;

    vector<int> dirx = {1, 0, -1, 0}, diry = {0, 1, 0, -1};

    bool isval(int xx, int yy){ return xx>=0 && xx<m && yy>=0 && yy<n; }

    int bfs(int targ){
        vector<vector<int>> vis(m, vector<int> (n, -1));
        
        queue<pii> q; 
        q.push({x,y}); 
        vis[x][y]=1;
        
        int dist=0;
        while(!q.empty()){
            int sz=q.size();
            while(sz--){
                auto [i,j] = q.front(); q.pop();
                if(vec[i][j] == targ) {x=i; y=j; return dist;}

                for(int k=0;k<4;k++){
                    int dx = i + dirx[k], dy = j + diry[k];
                    if(!isval(dx,dy) || !vec[i][j] || vis[dx][dy]!=-1) continue;
                    vis[dx][dy] = 1;
                    q.push({dx,dy});
                }
            }
            dist++;   
        }

        return -1; 
    }

    int cutOffTree(vector<vector<int>>& fr) {
        m=fr.size(), n=fr[0].size();
        if(!fr[x][y]) return -1; // if 0,0 is 0
        vec = fr;
        priority_queue<int, vector<int>, greater<int>> pq;
        for(auto a : fr){
            for(int i : a){
                if(i!=0 && i!=1) pq.push(i); 
            }
        }
        // while(!pq.empty()) { cout << pq.top() << " "; pq.pop(); }

        int steps=0;
        while(!pq.empty()){
            int targ = pq.top(); pq.pop();
            int smol_step = bfs(targ);
            if(smol_step == -1) return -1;
            steps += smol_step;
        }
        return steps;
    }
};
