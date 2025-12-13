class Solution {
public:
    int majorityElement(vector<int>& nums) {
        map<int,int> mp;
        for(int &x : nums) mp[x]++;
        int mx = INT_MIN, mxk = INT_MIN;
        for(auto it : mp){
            if(it.second > mx){
                mx = it.second;
                mxk = it.first;
            }
        }
        return mxk;
    }
};
