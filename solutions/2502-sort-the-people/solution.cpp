class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        int n=names.size();
        vector<int> idx(n);
        for(int i=0;i<n;i++) idx[i]=i;

        sort(idx.begin(), idx.end(), [&](int a, int b){
            return heights[a] > heights[b];
        });
        // for(int i : idx) cout << i << " ";
        vector<string> res;
        for(int i : idx){
            res.push_back(names[i]);
        }
        return res;
    }
};
