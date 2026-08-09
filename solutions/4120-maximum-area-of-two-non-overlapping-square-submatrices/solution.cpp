class Solution {
public:
    int n,m;
    vector<vector<int>> ps;
    bool isval(int k){
        int miro=m, maro=-1, micol=n, macol=-1;
        for(int i=0;i<=m-k;i++){
            for(int j=0;j<=n-k;j++){
                int sm = ps[i+k][j+k]-ps[i][j+k]-ps[i+k][j]+ps[i][j];
                if(sm == k*k){
                    miro = min(miro,i); maro = max(maro,i);
                    micol = min(micol,j); macol = max(macol,j);
                }
            }
        }
        if(maro==-1) return false;

        return maro-miro>=k || macol-micol>=k;  
    }

    int maxArea(vector<vector<int>>& mat) {
        m=mat.size(), n=mat[0].size();
        ps = vector<vector<int>>(m+1, vector<int>(n+1));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                ps[i+1][j+1] = mat[i][j]+ps[i][j+1]+ps[i+1][j]-ps[i][j];
            }
        }

        int l=1,r=min(n,m), ans=0;
        while(l<=r){
            int mi= (l+r)>>1;
            if(isval(mi)){
                ans = mi; l=mi+1;
            }else{
                r=mi-1;
            }
        }
        return ans*ans;
    }
};
