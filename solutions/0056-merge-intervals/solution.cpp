class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& it) {
        vector<vector<int>> res;
        sort(it.begin(), it.end());
        auto prev = it[0]; 
        for(int i=1; i<it.size();i++){
            auto cur = it[i];
            if(prev[1] >= cur[0]){
                // prev = {prev[0], max(prev[1], cur[1])};
                prev[1] = max(prev[1], cur[1]);
            }
            else{
                res.push_back(prev);
                prev = cur;
            }
        }
        res.push_back(prev);
        return res;
    }
};
