class Solution {
public:
    long long kitnicars(vector<int> &ranks, long long t){
        long long ans=0;
        for(int i : ranks){
            ans += sqrt(t/i);
        }
        return ans;
    }
    
    long long repairCars(vector<int>& ranks, int cars) {
        long long r=*max_element(ranks.begin(), ranks.end()), l=1;
        r*= (1ll*cars*cars);
        long long ans =0;
        while(l<=r){
            long long midtime = l+(r-l)/2;
            long long c = kitnicars(ranks, midtime);
            if(c >= cars){
                ans=midtime;
                r=midtime-1;
            }else{
                l=midtime+1;
            }
        }
        return ans;
    }
};
