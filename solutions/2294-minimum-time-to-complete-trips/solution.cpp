class Solution {
public:
    bool is(long long mi, vector<int>&v, int trp){
        long long trp_cnt = 0;
        for(int i=0;i<v.size();i++){
            trp_cnt += mi/v[i];
        }
        return trp_cnt >= trp;
    }

    long long minimumTime(vector<int>& time, int trp) {
        long long l=1,r=1ll* *min_element(time.begin(),time.end())*trp;
        long long ans=r;
        while(l<=r){
            long long mi = l+(r-l)/2;
            if(is(mi,time,trp)){
                ans = mi; r=mi-1;
            }else l=mi+1;
        }
        return ans;
    }
};
