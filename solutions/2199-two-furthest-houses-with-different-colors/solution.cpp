class Solution {
public:
    int maxDistance(vector<int>& colors) {
        int n = colors.size();
        int c1 =0, i=n-1;
        while(i>=0){
            if(colors[i] != colors[c1]) break;
            i--;
        }
        int c2 = n-1, j=0;
        while(j<n){
            if(colors[j] != colors[c2]) break;
            j++;
        }
        return max(n-j-1, i);
    }
};
