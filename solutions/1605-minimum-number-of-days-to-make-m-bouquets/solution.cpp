class Solution {
public:
    int minDays(vector<int>& bd, int m, int k) {
        // sort(bd.begin(), bd.end());
        int n=bd.size();
        int ans =-1;
        int l=1, r=*max_element(bd.begin(), bd.end());
        while(l<=r){
            int mi = l+(r-l)/2;
            int cnt=0, bouq=0;
            for(int i=0;i<n;i++){
                if(bd[i]<=mi)cnt++;
                else cnt=0;
                if(cnt==k){
                    bouq++; cnt=0;
                }
            }
            if(bouq >= m) {
                ans = mi; r=mi-1;
            }
            else l=mi+1;
        }
        return ans;
    }
};
