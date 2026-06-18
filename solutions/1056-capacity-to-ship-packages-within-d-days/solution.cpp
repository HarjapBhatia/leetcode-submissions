class Solution {
public:
    bool is(vector<int> &w, int mi, int d){
        int cnt=1, cur=0;
        for(int i:w){
            if(cur + i > mi){
                cnt++; cur=i;
            }else cur += i;
        }
        return cnt <= d;
    }
    
    int shipWithinDays(vector<int>& w, int days) {
        int l=*max_element(w.begin(), w.end());
        int r = accumulate(w.begin(), w.end(), 0);
        int ans = r;            
        while(l<=r){
            int mi = l+(r-l)/2;
            if(is(w, mi, days)){
                ans = mi;
                r=mi-1; 
            }else{
                l=mi+1; 
            }
        }
        return ans;
    }
};
