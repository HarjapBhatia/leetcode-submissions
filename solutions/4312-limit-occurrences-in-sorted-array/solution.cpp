class Solution {
public:
    vector<int> limitOccurrences(vector<int>& nums, int k) {
        map<int,int> mp;
        for(int x: nums) mp[x]++;
        vector<int> v;
        for(auto it : mp){
            int i=min(it.second,k);
            while(i--)
                v.push_back(it.first);
        }
        return v;
    }
};
