class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int mi=*min_element(nums.begin(),nums.end());
        int mx=*max_element(nums.begin(),nums.end());
        unordered_set<int> us(nums.begin(),nums.end());
        vector<int> res;
        for(int i=mi;i<=mx;i++){
            if(us.find(i) == us.end()) res.push_back(i);
        }
        return res;
    }
};
