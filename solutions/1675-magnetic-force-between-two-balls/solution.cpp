class Solution {
public:
    bool is(vector<int>&pos, int mi, int m){
        int cnt=1, last=pos[0];
        for(int i=1;i<pos.size();i++){
            if(pos[i] - last >= mi){
                cnt++; last = pos[i];
            }
        }
        return cnt >= m;
    }
    int maxDistance(vector<int>& pos, int m) {
        int n=pos.size();
        sort(pos.begin(), pos.end());
        int l=1, r=pos[n-1];
        int ans = 0;
        while(l<=r){
            int mi = l+(r-l)/2;
            if(is(pos, mi, m)){
                ans = mi; l=mi+1; 
            }else r=mi-1;
        }
        return ans;
    }
};
