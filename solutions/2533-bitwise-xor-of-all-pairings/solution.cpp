class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int n1=nums1.size(), n2=nums2.size();
        // unordered_map<long long,long long> mp;
        // for(int i:nums1){
        //     mp[i] += n2;
        // }
        // for(int i : nums2){
        //     mp[i] += n1;
        // }
        // int ans =0;
        // for(auto it : mp){
        //     if(it.second&1) ans ^= it.first;
        // }
        // return ans;
        int ans=0;
        if(n2&1){
            for(int i:nums1) ans ^= i;
        }
        if(n1&1){
            for(int i:nums2) ans ^= i;
        }
        return ans;
    }
};
