class Solution {
public:
    vector<int> maxKDistinct(vector<int>& nums, int k) {
        unordered_set<int> dist(nums.begin(), nums.end());
        vector<int> vec(dist.begin(), dist.end());
        sort(vec.begin(), vec.end(), greater<int>());
        if (vec.size() > k) vec.resize(k);
        return vec;
    }
};
