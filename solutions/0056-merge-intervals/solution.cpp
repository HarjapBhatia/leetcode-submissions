class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& iv) {
        vector<vector<int>> res;
        sort(iv.begin(), iv.end());
        auto prv = iv[0];
        for(int i=1;i<iv.size();i++){
            auto cur = iv[i];
            if(cur[0] <= prv[1]) 
                prv = {prv[0], max(prv[1], cur[1])};
            else{
                res.push_back(prv);
                prv = cur;
            }
        }
        res.push_back(prv);
        return res;
    }
};
