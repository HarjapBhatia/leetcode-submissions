class Solution {
public:
    void rs(vector<int>&vec, int k){
        k%=vec.size();
        reverse(vec.begin(), vec.end());
        reverse(vec.begin(), vec.begin()+k);
        reverse(vec.begin()+k, vec.end());
    }

    void ls(vector<int>&vec, int k){
        k%=vec.size(); int n = vec.size();
        reverse(vec.begin(), vec.end());
        reverse(vec.begin(), vec.begin()+(n-k));
        reverse(vec.begin()+(n-k), vec.end());

    }

    bool areSimilar(vector<vector<int>>& mat, int k) {
        vector<vector<int>> res = mat;
        for(int i=0;i<mat.size();i++){
            if(i&1) rs(res[i],k);
            else ls(res[i],k);
        }
        return res==mat;
    }
};
