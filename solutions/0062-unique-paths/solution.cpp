class Solution {
public:
    int uniquePaths(int m, int n) {
        // (m+n-2)c(n-1)
        int mx=max(m,n);
        long long res=1;
        for(int i=m+n-2, j=1; i>=mx; i--,j++)
            res = (res*i)/j;
        
        return res;
    }
};
