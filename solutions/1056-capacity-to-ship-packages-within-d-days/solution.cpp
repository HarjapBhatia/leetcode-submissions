class Solution {
public:
    int shipWithinDays(vector<int>& w, int days) {
        int n = w.size();
        int ans =0, sm =0;
        for(int x : w) sm += x;
        int l=*max_element(w.begin(), w.end()), r=sm;
        while(l<=r){
            int mi = l+(r-l)/2;

            int cnt=1, tmp=0;
            for(int i=0;i<w.size();i++){
                if(tmp+w[i] <= mi){
                    tmp += w[i];
                }else{
                    tmp=w[i]; cnt++;
                }
            }

            if(cnt <= days){
                ans=mi; r=mi-1;
            }else l=mi+1;
        }
        return ans;
    }
};
