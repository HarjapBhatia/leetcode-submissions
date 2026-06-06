class Solution {
public:
    long long minEnergy(int n, int b, vector<vector<int>>& iv) {
        sort(iv.begin(), iv.end());
        vector<vector<int>> mrg;
        auto prv = iv[0];
        for(int i=1;i<iv.size();i++){
            auto cur=iv[i];
            if(prv[1] >= cur[0]) prv[1] = max(prv[1], cur[1]);
            else{
                mrg.push_back(prv); prv=cur;
            }
        }
        mrg.push_back(prv);

        long long bulbreq = (b%3==0 ? b/3 : (b/3)+1);
        long long t = 0;
        for(auto x : mrg){
            t += (x[1]-x[0]+1);
        }
        return (long long)t*bulbreq;
    }
};
