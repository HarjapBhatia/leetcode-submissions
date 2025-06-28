#include<algorithm>
class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        vector<int> cpy = nums;
        sort(cpy.begin(),cpy.end(),greater<int>());
        cpy.resize(k);
        map<int,int> f;
        for(int i:cpy){
            f[i]++;
        }
        vector<int> v;
        for(int x:nums){
            if (f[x]>0){
                v.push_back(x);
                f[x]--;
            }
        }
        return v;
    }
};
