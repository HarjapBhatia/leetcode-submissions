class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        int n = mat.size(), m = mat[0].size();
        vector<int> idx(n), cnt(n);
        for(int i=0;i<n;i++){
            idx[i] = i;
            cnt[i] = accumulate(mat[i].begin(), mat[i].end(), 0);
        }
        sort(idx.begin(), idx.end(), [&](int a, int b){
            if(cnt[a] == cnt[b]) return a<b;
            return cnt[a] < cnt[b];
        });
        vector<int> res;
        for(int i=0;i<k;i++) res.push_back(idx[i]);
        return res;
    }
};
