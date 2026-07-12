class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        int n=arr.size();
        vector<int> t=arr;
        sort(t.begin(),t.end());
        unordered_map<int,int>mp;
        int j=1;
        for(int i=0;i<n;i++){
            if(mp.find(t[i]) == mp.end()) mp[t[i]] = j++;
        }
        for(int i=0;i<n;i++){
            t[i] = mp[arr[i]];
        }
        return t;
    }
};
