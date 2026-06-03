class Solution {
public:
    int minEatingSpeed(vector<int>& p, int h) {
        int n = p.size(), ans = 0;
        // sort(p.begin(), p.end());
        int l = 1, r=*max_element(p.begin(), p.end());
        // int mi = r;
        while(l<=r){
            int mi = l+(r-l)/2;
            long long t=0;
            for(int i : p){
                t += (long long)(i+mi-1)/mi;    
            }       
            // if(t==h) return t;
            if(t <= h){
                ans = mi; r=mi-1;
            }
            else l=mi+1;
        }
        return ans;
    }
};
